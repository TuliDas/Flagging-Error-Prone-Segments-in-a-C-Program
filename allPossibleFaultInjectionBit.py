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

    def calculatePercentage(self,B,total):
        
        bit = {}
        bitsPerStatements = 64

        for i in B:
            temp = B[i] * bitsPerStatements
            #bit[i] = ( pow(2,temp) / total )
            bit[i] =  ( temp / total ) * 100 
        


        return bit
    def calculateHighestPercentageBlock(self,B):
        mx = -1
        temp = {}
        for i in B:
            if B[i] > mx:
                mx = B[i]
        
        for i in B:
            if B[i] == mx:
                temp[i] = B[i]
        
        return temp
          
    

    def blockWisePossibleBit(self,total,B1,B2,B3,strr):
         
        bit_ifElse = self.calculatePercentage(B1,total)
        bit_Loop = self.calculatePercentage(B2,total)
        bit_Function = self.calculatePercentage(B3,total)

        
        self.ShowTheTableOfPercentage(bit_ifElse,bit_Loop,bit_Function)
        

    def ShowTheTableOfPercentage(self,b1,b2,b3):
        Highest_ifElse = self.calculateHighestPercentageBlock(b1)
        Highest_Loop = self.calculateHighestPercentageBlock(b2)
        Highest_Function = self.calculateHighestPercentageBlock(b3)
        
        


    
      
        



