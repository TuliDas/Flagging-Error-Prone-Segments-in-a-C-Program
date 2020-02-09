
import re

class Utility:
    def __init__(self):
        print("Inside Utility Constructor")

    def Function_Check(self, line):
        if re.search("[^\s]+[\s]+[^(]+[(][^)]*[)]", line) == None:
            return False

        return True
        
        

    def Statement_Check(self, line):
        pass