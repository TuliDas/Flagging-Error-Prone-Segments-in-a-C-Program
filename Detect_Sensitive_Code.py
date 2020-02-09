import re
import subprocess



class Detect_Sensitive_Code:
    def __init__(self, inputFileName):
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
            for word in line.split():
                
                #FUNCTION CHECK#
                temp = line.split()
                if ( ('(' in line) and (')' in line) and (';' not in line ) and ('=' not in line ) and ( temp[0]=="int" or temp[0]=="float" or temp[0]=="double" or temp[0]=="char" or temp[0]=="string" or temp[0]=="void" )    ):
                    f.write(line)
                    f.write('\n')
                    break
                #STATEMENT CHECK#
                if(word[0]!="#" and word[0]!="{" and word[0]!="}" and word!="using" and (not word.startswith("if")) and (not word.startswith("else")) and (not word.startswith("for")) and (not word.startswith("return")) and (not word.startswith("//"))  and line!="int main()"):
                    f.write('printf("line = %d\\n",__LINE__);')
                    f.write(line)
                    f.write('\n')
                    break

                else:
                    f.write(line)
                    f.write('\n')
                    break
        f.close()
        return fileName


    def executeProcessedSourceCode(self, inputFileName):
        cmd = "test.cpp"
        subprocess.call(["g++","-o", "b", cmd]) 
        subprocess.call("b.exe")
        return "outputC.txt"


    def highlightStatements(self, inputFileName):
        f2 = open('outputC.txt')
        l2 = f2.read().splitlines()

        lineNumbers = []
        for line in l2:
            word = line.split()
            if word[0]=='line':
                lineNumbers.append(int(word[2]))

        #print(lineNumbers)

        f3 = open('inputB.cpp')
        l3 = f3.read().splitlines()

        counter = 0
        stringfff = "<html><body>"
        for line in l3:
            counter = counter + 1
            if(line == 'freopen("outputC.txt", "w+", stdout);'):
                stringfff += ''
                
            elif counter in lineNumbers:
                cc = 0
                for x in lineNumbers:
                    if x == counter:
                        cc+=1
            
                stringfff += '<p style="color:blue">' + line + '   // executed ' + str(cc) + ' times' + '</p>'
            else:
                stringfff += '<p style="color:black">' + line + '</p>'
            

        stringfff += "</body></html>"

        f2.close()
        f3.close()
        f = open("report.html", "w")
        f.write(stringfff)
        f.close()





def main():
    obj = Detect_Sensitive_Code("inputA.cpp")
    
if __name__ == '__main__':
    main()

