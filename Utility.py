import re

class Utility:
    def __init__(self):
        print("Inside Utility Constructor")

    def Function_Check(self, line):
        if line.startswith("else if"):
            return False

        if re.search("[\w*]+[\s]+[\w]+[\s]*[(][^)]*[)]", line) == None:
            return False
        return True

    def Function_CallName(self,line):
        if re.search("[\w]+[\s]*[(][^)]*[)];", line) == None:
            return 'null'
        #if 'printf' in line or 'scanf' in line:
            #return 'null'
            
        res = re.findall("[\w]+[\s]*[(][^)]*[)];", line)
        ret = ""
        for c in res[0]:
            if c == '(':
                break
            else:
                ret = ret + c
        return ret


    def Loop_Check(self,line):
        if (re.search("for[\s]*[(].*[)]", line) == None)  and (re.search("while[\s]*[(].*[)]", line) == None):
            return False
        return True
        
    def Statement_Check(self, line):
        if (  ("{" in line) or ("}" in line) ):
            return False
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
        
    def Handeling_Html_Tag(self,line):
        if '<' not in line and '>' not in line :
            return line

        strr = ""
        for i in line:
            if(i=='<' or i=='>'):
                strr += i
                strr += ' '
            else:
                strr += i
        return strr
