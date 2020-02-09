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
