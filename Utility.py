import re

class Utility:
    def __init__(self):
        print("Inside Utility Constructor")

    def Function_Check(self, line):
        if re.search("[\w*]+[\s]+[\w]+[\s]*[(][^)]*[)]", line) == None:
            return False
        return True

    def Loop_Check(self,line):
        if re.search("for[\s]*[(].*[)]", line) == None:
            return False
        return True
        
    def Statement_Check(self, line):
        if re.search("[^;]+;", line) == None:
            return False
        return True

    def Statement_Get(self, line):
        return re.findall("[^;]+;", line)

    def If_Check(self, line):
        if(line.startswith("if")):
            return True
        return False

    def Else_Check(self, line):
        if(line.startswith("else")):
            return True
        return False

    def ElseIf_Check(self, line):
        if(line.startswith("else if")):
            return True
        return False

    def NonStatement_Declaration(self, line):
        
        if(self.Statement_Check(line)):
            return "null"

        if(self.Function_Check(line)):
            s = "Function"
            return s
        if(self.Loop_Check(line)):
            s = "Loop"
            return s
        if(self.If_Check(line)):
            s = "If"
            return s
        if(self.Else_Check(line)):
            s = "Else"
            return s
        if(self.ElseIf_Check(line)):
            s = "Else if"
            return s
        
        return "null"
        


    def Handeling_HeaderFile(self,line):
        strr = ""
        for i in line:
            if(i=='<' or i=='>'):
                strr += i
                strr += ' '
            else:
                strr += i
        return strr
