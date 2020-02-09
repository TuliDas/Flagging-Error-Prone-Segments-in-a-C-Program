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

            if( (line == "int main()" or line == "{") and done == 0 ):
                write_statement += line
        f.close()
        return fileName


    def addLineNumberBeforeStatement(self, inputFileName):
        f = open (inputFileName)
        lines = f.read().splitlines()
        f.close()
        fileName = "test.cpp"
        f = open(fileName, "w")

        for line in lines:
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
            if self.utility.Loop_Check(line) == False:
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
        cmd = inputFileName
        subprocess.call(["g++","-o", "b", cmd]) 
        subprocess.call("b.exe")
        return "outputC.txt"


    def getColorByRank(self, rank):
        if rank == 4:
            return "red"
        if rank == 3:
            return "orange"
        if rank == 2:
            return "purple"
        if rank == 1:
            return "blue"
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
        
        #print(countTrac)

        sorted_x = sorted(countTrac.items(), key=lambda kv: kv[1])
        sorted_x.reverse()
        #print(sorted_x)
        max_freq = sorted_x[0][1]
        min_freq = sorted_x[len(sorted_x)-1][1]




        resRank = 0
        for (lineNumber, freq) in sorted_x:
            if freq >= max_freq:
                resRank = 4
            elif freq == min_freq :
                resRank = 1
            elif freq == 2:
                resRank = 2
            elif freq<max_freq and freq>2:
                resRank = 3
            else:
                resRank = 0
            rank[lineNumber] = self.getColorByRank(resRank)
                
            

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
                
                if curColor =="red":    
                    stringfff += '<p style="font-family:verdana;font-weight:bold;color:'+curColor+'">' + line + '   //(MOST SENSITIVE portion), executed ' + str(cc) + ' times' + '</p>\n'
                else:
                    stringfff += '<p style="font-family:verdana;font-weight:bold;color:'+curColor+'">' + line + '   //executed ' + str(cc) + ' times' + '</p>\n'

            else:
                stringfff += '<p style="font-family:verdana;font-weight:bold;color:black">' + line + '</p>\n'
            

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

