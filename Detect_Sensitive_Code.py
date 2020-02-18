import re
import subprocess
import statistics
import copy
import Utility
import ParenthesisBalance
import HighlightExecutedStatements
import HighlightHeuristics

class Detect_Sensitive_Code:
    
    utility = None
    parenthesisBalance = None
    highlightStatements = None
    highlightHeuristics = None 

    def __init__(self, inputFileName):
        
        self.utility = Utility.Utility()
        self.parenthesisBalance = ParenthesisBalance.Parenthesis_Balance()
        self.highlightStatements = HighlightExecutedStatements.Highlight_Executed_Statements()
        self.highlightHeuristics = HighlightHeuristics.Highlight_Heuristics()

        processedFileName = self.removeEmptyLines(inputFileName) # -> InputA.cpp
        allFunctionName = self.getAllFunctionName(processedFileName) #-> allFunctionName
        getTrackOfBlock = self.parenthesisBalance.TrackCalculation(processedFileName) #Function, Loop, If track
        justBlock = self.updateBlock(getTrackOfBlock)  # -> block start and end report
        processedFileName = self.addLineNumberBeforeStatement(processedFileName,justBlock) # -> InputB.cpp
        processedFileName = self.addBlockwiseLineNumber(processedFileName, getTrackOfBlock,justBlock) #-> inputC.cpp
        processedFileName = self.executeProcessedSourceCode(processedFileName)
        self.highlightStatements.highlightExecutedStatements(processedFileName)
        self.getAllHeuristicsAndHighlight(processedFileName , getTrackOfBlock, allFunctionName)
        print("Operation Successful")
        

    def removeEmptyLines(self, inputFileName):
        f = open (inputFileName)
        lines = f.read().splitlines()
        f.close()

        fileName = "InputA.cpp"
        f = open(fileName, "w")

        line = "static int global_loop_id = 0, global_ifelse_id = 0, global_function_id = 0;"
        
        f.write(line)
        f.write("\n")
        
        done = 0 
        for line in lines:

            if line == "":
                f.write(line)
                continue

            if(line.startswith("int main()") and done == 0):
                done += 1
                f.write(line)
                f.write('\n')
                continue

            elif(done == 1):
                done+=1
                f.write(line + ' freopen("Output.txt", "w+", stdout);')
                f.write('\n')

            else:
                res = self.utility.Statement_Get(line)
                if self.utility.Loop_Check(line) == False:
                    if len(res) > 0:
                        for x in res:
                            f.write(x)
                            f.write('\n')
                    else:
                        f.write(line)
                        f.write('\n')
                else:
                    f.write(line)
                    f.write('\n')

        f.close()
        return fileName



    def addLineNumberBeforeStatement(self, inputFileName,blockTrack):
        f = open (inputFileName)
        lines = f.read().splitlines()
        f.close()
        fileName = "InputB.cpp"
        f = open(fileName, "w")

        write_statement = 'freopen("Output.txt", "w+", stdout);'
        cnt = 0

        for line in lines:
            cnt+=1
            if "global_loop_id" in line and "global_ifelse_id" in line and "global_function_id" in line:
                f.write(line)
                f.write('\n')
                continue
            if (write_statement in line):
                f.write(line)
                f.write('\n')
                continue

            if ( self.ifInsideBlock(blockTrack , cnt) == False):
                f.write(line)
                f.write('\n')
                continue


            if (  ("{" in line) or ("}" in line) ):
                f.write(line)
                f.write('\n')
                continue

            if(line==""):
                continue

            words = line.split()
                
            #FUNCTION CHECK#
            if self.utility.Function_Check(line) == True:
                f.write(line)
                f.write('\n')
                continue

            #STATEMENT CHECK#
            if "using" in words and "namespace" in words:
                f.write(line)
                f.write('\n')
                continue
            
            res = self.utility.Statement_Get(line)
            if self.utility.Loop_Check(line) == False and self.ifInsideBlock(blockTrack,cnt)==True:
                if len(res) > 0:
                    for x in res:
                        f.write('printf("line = %d\\n",__LINE__);')
                        f.write(x)
                        f.write('\n')
                else:
                    f.write(line)
                    f.write('\n')
            else:
                f.write(line)
                f.write('\n')

        f.close()
        return fileName

    def checkIfExists(self, dictData, val):
        for key in dictData.keys():    
            if dictData[key] == val:
                return True
        return False

    def ifInsideBlock(self, dictData, lineNum):
        for st in dictData.keys():    
            ed = dictData[st]
            if st <= lineNum and lineNum <= ed:
                return True
        return False

    def updateBlock(self,info):
        #print(info)
        temp = {}
        for i in info.keys():
            temp[i] = info[i][0]

        #print(temp)
        return temp

    def addBlockwiseLineNumber(self, inputFileName, trackOfBlock,blockTrack):
        reader = open(inputFileName)
        fileName = "InputC.cpp"
        writer = open(fileName, "w")
        lines = reader.read().splitlines()
        
        if_dict = self.parenthesisBalance.IfTrackCalculation(trackOfBlock)
        else_dict = self.parenthesisBalance.ElseTrackCalculation(trackOfBlock)
        elseIf_dict = self.parenthesisBalance.ElseIfTrackCalculation(trackOfBlock)

        mergedIfElse = dict()
        mergedIfElse.update(if_dict)
        mergedIfElse.update(else_dict)
        mergedIfElse.update(elseIf_dict)


        function_dict = self.parenthesisBalance.FunctionTrackCalculation(trackOfBlock)
        loop_dict = self.parenthesisBalance.LoopTrackCalculation(trackOfBlock)
        #loop_level = self.parenthesisBalance.LoopLeveling(loop_dict)

        cnt = 0
        for line in lines:
            cnt = cnt + 1

            strToWrite = ''
            if 'return' in line and self.ifInsideBlock(blockTrack,cnt):
                ss = self.utility.Statement_Get(line)
                if self.ifInsideBlock(mergedIfElse, cnt):
                    strToWrite = strToWrite + 'printf("ifelse_end_id %d line = %d\\n", global_ifelse_id--, __LINE__);'
                if self.ifInsideBlock(loop_dict, cnt):
                    strToWrite = strToWrite + 'printf("loop_end_id %d line = %d\\n", global_loop_id--, __LINE__);'
                if self.ifInsideBlock(function_dict, cnt):
                    strToWrite = strToWrite + 'printf("function_end_id %d line = %d\\n", global_function_id--, __LINE__);'
                strToWrite = ss[0] + strToWrite + ss[1] 
                
                writer.write(strToWrite)
                writer.write('\n')
                continue
            
            if (cnt - 1) in function_dict:
                line += 'printf("function_start_id %d line = %d\\n", ++global_function_id, __LINE__);'
            if self.checkIfExists(function_dict, cnt):
                line = 'printf("function_end_id %d line = %d\\n", global_function_id--, __LINE__);' + line
            if (cnt - 1) in mergedIfElse:
                line += 'printf("ifelse_start_id %d line = %d\\n", ++global_ifelse_id, __LINE__);'
            if self.checkIfExists(mergedIfElse, cnt):
                line = 'printf("ifelse_end_id %d line = %d\\n", global_ifelse_id--, __LINE__);' + line
            if (cnt) in loop_dict:
                line = 'printf("loop_start_id %d line = %d\\n", ++global_loop_id, __LINE__);' + line
            if self.checkIfExists(loop_dict, cnt):
                line += 'printf("loop_end_id %d line = %d\\n", global_loop_id--, __LINE__);'          

            writer.write(line)
            writer.write('\n')
        
        writer.close()
        reader.close()
        return fileName

    def executeProcessedSourceCode(self, inputFileName):
        cmd = inputFileName
        outputFileName = "Output.txt"

        subprocess.call(["g++","-o", "b", cmd]) 
        subprocess.call("b.exe")
        return outputFileName 


    def calculateStatementsForHeuristics(self, instruction_set):
        instruction_set.append([-1, -1])
        ret = {}
        st = []
        st.append([-1,-1])
        for ls in instruction_set:
            sz = len(st)
            if ls[0] == 0:
                for ss in st:
                    tup = (ss[0], ss[1])
                    if tup in ret:
                        ret[tup] += 1
                    else:
                        ret[tup] = 1
            elif ls[0] == st[sz - 1][0]:
                st.pop()
            else:
                st.append(ls)
        
        return ret

    def calculateFunctioncallLevel(self, fn_list, loop_list):
        ret = {}
        st = []
        st.append([-1,-1])
        for ls in loop_list:
            sz = len(st)
            if ls[0] == 0:
                for ln in fn_list:
                    if ln[0] == ls[1]:
                        ret[ln] = sz
                        break
            elif ls[0] == st[sz - 1][0]:
                st.pop()
            else:
                st.append(ls)
        ret_dic = {}
        for rr in ret.keys():
            ret_dic[rr[1]] = []
        for rr in ret.keys():
            lineno = rr[0]
            fn_name = rr[1]
            cnt = ret[rr]
            ret_dic[fn_name].append((lineno, cnt))
        for fn in ret_dic:
            mini = 99999
            for val in ret_dic[fn]:
                mini = min(mini, val[1])
            new_list = []
            for val in ret_dic[fn]:
                if val[1] == mini:
                    new_list.append(val)
            ret_dic[fn] = new_list
        #print(ret_dic)
        return ret


    def getAllFunctionName(self, inputFileName):
        f = open (inputFileName)
        lines = f.read().splitlines()
        f.close()
        cnt = 0
        ret = []
        for line in lines:
            cnt += 1
            line = line.strip()
            res = self.utility.Function_CallName(line)
            if(res == 'null'):
                continue
            else:
                ret.append((cnt, res))
        return ret
    
    def getOptimalHeuristics(self,info):
        #print(info)
        ans = []
        mx_freq = -1
        for i in info.keys():
            if(i[0] == 1):
                if info[i] >= mx_freq:
                    mx_freq = info[i]

        for i in info.keys():
            if info[i] == mx_freq and i[0] == 1:
                ans.append(i[1])

        #print(ans)
        return ans

    def getFunctionStatement(self,info):
        ans = {}

        for i in info.keys():
            if(i[0] == -1):
                continue
            ans[i[1] - 1] = info[i]

        ans = sorted(ans.items(), key=lambda kv: kv[1])
        return ans  
    
    def findFunctionDefinition(self, inputFileName ,info,H3,fun):
        fun2 = {}
        f2 = open(inputFileName)
        l2 = f2.read().splitlines()
        f2.close()

        for i in info:
            strr = i
            cnt = 0

            for line in l2:
                cnt += 1
                
                if( cnt not in fun.keys()):
                    continue
                
                if (strr in line) and (cnt in fun.keys()):
                    fun2[cnt] = fun[cnt]  
        
        cnt = 0
        for line in l2:
            cnt += 1
            if ( ( 'return' in line ) and self.ifInsideBlock(fun2,cnt) ) :
                H3.append(cnt)

        #print(H3)    
        return H3

    def discardBuiltInFunction(self,level,track):
        l1 = []
        l2 = []
        for i in track.keys():
            l1.append(i)
        
        for i in level.keys():
            l2.append(i[1])
    

        f2 = open('InputA.cpp')
        l3 = f2.read().splitlines()
        f2.close()
        
        l_final = []
        cnt = 0

        for line in l3:
            cnt += 1
            if cnt in l1:
                for i in l2:
                    if i in line:
                        l_final.append(i)
                        break
        
        temp = {}

        for i in level.keys():
            if i[1] not in l_final:
                continue
            j = (i[0],i[1])
            temp[j] = level[i]
        
        #print(level)
        #print(temp)
        return temp        

    def findResultantFunction(self,info):
        temp = []
        ans = []
        mn_lvl = 1000000000000 
        for i in info.keys():
            if info[i] < 2 :
                continue
            if info[i] < mn_lvl :
                mn_lvl = info[i]

        for i in info.keys():
            if info[i] == mn_lvl:
                temp.append(i[0])
                if i[1] not in ans:
                    ans.append(i[1])

        #print(temp)
        #print(ans)
        return ans,temp


    def getAllHeuristicsAndHighlight(self, inputFileName , trackOfBlock, fn_name):

        f2 = open(inputFileName)
        l2 = f2.read().splitlines()
        f2.close()
        fileName = "InputA.cpp"
        loop_temp = []
        ifelse_temp = []
        function_temp = []

        for line in l2:
            word = line.split()
            if word[0]=='line':
                temp = [0,int(word[2])]
                loop_temp.append(temp)
                ifelse_temp.append(temp)
                function_temp.append(temp)
                continue
            
            else:
                if (word[0] == 'loop_start_id'):
                    temp = [int(word[1]) , int(word[4])]
                    loop_temp.append(temp)
                    continue

                if (word[0] == 'loop_end_id'):
                    temp = [int(word[1]) , int(word[4])]
                    loop_temp.append(temp)
                    continue

                if (word[0] == 'ifelse_start_id'):
                    temp = [int(word[1]) , int(word[4])]
                    ifelse_temp.append(temp)
                    continue
                    
                if (word[0] == 'ifelse_end_id'):
                    temp = [int(word[1]) , int(word[4])]
                    ifelse_temp.append(temp)
                    continue

                if (word[0] == 'function_start_id'):
                    temp = [int(word[1]) , int(word[4])]
                    function_temp.append(temp)
                    continue
                    
                if (word[0] == 'function_end_id'):
                    temp = [int(word[1]) , int(word[4])]
                    function_temp.append(temp)
                    continue
    
        
        # --- ifElse Heuristics --- #
        ifelse_final = self.calculateStatementsForHeuristics(ifelse_temp)
        H1_IfElseifElse = self.getOptimalHeuristics(ifelse_final)

        for i in range(len(H1_IfElseifElse)):
            H1_IfElseifElse[i] -= 1
        
        # ------ Loop Terminating Branch ---- #
        loop_final = self.calculateStatementsForHeuristics(loop_temp)
        H2_Loop = self.getOptimalHeuristics(loop_final)

        # ------- Function Terminating Branch -----# 
        H3_Function = [] 
        function_dict = self.parenthesisBalance.FunctionTrackCalculation(trackOfBlock)
        function_final = self.calculateStatementsForHeuristics(function_temp)
        function_final = self.getFunctionStatement(function_final)
        function_level_cnt = self.calculateFunctioncallLevel( fn_name , loop_temp)
        function_level_cnt = self.discardBuiltInFunction(function_level_cnt,function_dict)
        function_ans , H3_Function = self.findResultantFunction(function_level_cnt)
        H3_Function = self.findFunctionDefinition(fileName, function_ans , H3_Function,function_dict)
               
        
        self.highlightHeuristics.highlightingHeuristics(fileName,H1_IfElseifElse,H2_Loop,H3_Function)
        

def main():
    obj = Detect_Sensitive_Code("EDCproneCode.cpp")

if __name__ == '__main__':
    main()