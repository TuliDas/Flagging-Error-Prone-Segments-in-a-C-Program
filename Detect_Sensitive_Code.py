import re
import subprocess
import Utility
import statistics
import copy


class Detect_Sensitive_Code:
    utility = None

    def __init__(self, inputFileName):
        self.utility = Utility.Utility()
        processedFileName = self.removeEmptyLines(inputFileName)
        processedFileName = self.addLineNumberBeforeStatement(processedFileName)
        processedFileName = self.executeProcessedSourceCode(processedFileName)
        self.highlightStatements(processedFileName)
        print("Operation Completed")


    def removeEmptyLines(self, inputFileName):
        f = open (inputFileName)
        lines = f.read().splitlines()
        f.close()
        fileName = "inputB.cpp"
        f = open(fileName, "w")
        write_statement = ""
        done = 0 
        for line in lines:
            if(line==""):
                continue
            #ADDING NEW_STATEMENT (freopen OUT)#
            if("int main()" in write_statement and ("{" in write_statement) and done == 0):
                f.write(line)
                f.write('\n')
                f.write('freopen("outputC.txt", "w+", stdout);')
                f.write('\n')
                done = 1
            else:
                res = re.findall("[^;]+;", line)
                if re.search("for[\s]*[(].*[)]", line) == None:
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

            if( (line == "int main()" or line == "{") and done == 0 ):
                write_statement += line
        f.close()
        return fileName


    def addLineNumberBeforeStatement(self, inputFileName):
        f = open (inputFileName)
        lines = f.read().splitlines()
        fileName = "test.cpp"
        f = open(fileName, "w")
        for line in lines:
            if(line==""):
                continue

            words = line.split()
                
            #FUNCTION CHECK#
            if self.utility.Function_Check(line):
                f.write(line)
                f.write('\n')
                continue
            #STATEMENT CHECK#
            # if(word[0]!="#" and word[0]!="{" and word[0]!="}" and word!="using" and (not word.startswith("if")) and (not word.startswith("else")) and (not word.startswith("for")) and (not word.startswith("return")) and (not word.startswith("//"))  and line!="int main()"):
            
            if "using" in words and "namespace" in words:
                f.write(line)
                f.write('\n')
                continue

            res = re.findall("[^;]+;", line)
            if re.search("for[\s]*[(].*[)]", line) == None:
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


    def executeProcessedSourceCode(self, inputFileName):
        cmd = "test.cpp"
        subprocess.call(["g++","-o", "b", cmd]) 
        subprocess.call("b.exe")
        return "outputC.txt"


    def getColorByRank(self, rank):
        if rank == 5:
            return "red"
        if rank == 4:
            return "orange"
        if rank == 3:
            return "blue"
        if rank == 2:
            return "green"
        return "black"
        

    def highlightStatements(self, inputFileName):

        f2 = open('outputC.txt')
        l2 = f2.read().splitlines()

        lineNumbers = []
        for line in l2:
            word = line.split()
            if word[0]=='line':
                lineNumbers.append(int(word[2]))

        rank = dict()
        countTrac = dict()
        tempList = copy.deepcopy(lineNumbers)

        for x in tempList:
            if x not in countTrac.keys():
                countTrac[x] = 1
            else:
                countTrac[x] += 1
        
        print(countTrac)

        sorted_x = sorted(countTrac.items(), key=lambda kv: kv[1])
        sorted_x.reverse()

        loopFreq = 100000
        loopRank = 6
        for (lineNumber, freq) in sorted_x:
            if freq < loopFreq:
                loopFreq = freq
                loopRank = loopRank - 1
            
            if loopRank < 2:
                loopRank = 2
            rank[lineNumber] = self.getColorByRank(loopRank)
                
            


        
        
        

        
        #print(lineNumbers)

        f3 = open('inputB.cpp')
        l3 = f3.read().splitlines()

        counter = 0
        stringfff = "<html><body><code>\n"
        for line in l3:
            counter = counter + 1
            if(line == 'freopen("outputC.txt", "w+", stdout);'):
                stringfff += ''
                
            elif counter in lineNumbers:
                cc = 0
                for x in lineNumbers:
                    if x == counter:
                        cc+=1
            
                if counter in rank.keys():
                    curColor = rank[counter]
                else:
                    curColor = "black"
                stringfff += '<p style="color:'+curColor+'">' + line + '   // executed ' + str(cc) + ' times' + '</p>\n'
            else:
                stringfff += '<p style="color:black">' + line + '</p>\n'
            

        stringfff += "</code></body></html>\n"

        f2.close()
        f3.close()
        f = open("report.html", "w")
        f.write(stringfff)
        f.close()





def main():
    obj = Detect_Sensitive_Code("inputA.cpp")

if __name__ == '__main__':
    main()

