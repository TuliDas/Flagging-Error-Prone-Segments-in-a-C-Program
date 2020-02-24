import Utility
import copy

class Faulty_Binary_Bit:
    utility = None

    def __init__(self):

        self.utility = Utility.Utility() 
        print("Successfully Found Corresponding Binary Bit")


    def wholePossibleBinaryBit(self,inputFileName):
        f = open (inputFileName)
        lines = f.read().splitlines()
        f.close()

        bitsPerStatements = 64
        ans = 0

        for line in lines:
            if line.startswith('line'):
                ans += bitsPerStatements
        
        #ans = pow(2,ans)
        return ans
    

    def blockWisePossibleBit(self,total,B1,B2):
        bit1 = {}
        bit2 = {}
        bit3 = {}
        bitsPerStatements = 64

        for i in B1:
            temp = B1[i] * bitsPerStatements
            #bit1[i] = ( pow(2,temp) / total )
            bit1[i] =  ( temp / total ) * 100 

        for i in B2:
            temp = B2[i] * bitsPerStatements
            #bit1[i] = ( pow(2,temp) / total )
            bit2[i] =  ( temp / total ) * 100 

        #print(bit2)
        



