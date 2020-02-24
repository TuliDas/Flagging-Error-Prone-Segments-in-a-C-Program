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
                #ans -= 1

        return ans

    def calculatePercentage(self,B,total,strr):
        
        bit = {}
        bitsPerStatements = 64

        for i in B:
            s=''
            for j in range(i[0],i[1]+1):
                s+= '<p>' + strr[j] + '</p>'

            temp = (B[i]) * bitsPerStatements
            #xxx = temp-total
            #print(xxx)
            #bit[s] =  pow(2,xxx) * 100
            bit[s] = (temp/total) * 100

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
          
    def tableMaking(self,B,title,clr,blr,H):

        stringff = '<table border="2" style="width:70%">'
        stringff+= '<caption style="font-family:italic;font-size:20;font-weight:bold;color:#2b20a1 ">' + title + '</caption>'
        
        stringff += '<tr>'
        stringff += '<th> Block </th>'
        stringff += '<th> Bit Percentage </th>'
        stringff += '</tr>'

        for line in B:
            if B[line] in H.values():
                curColor = clr
                burColor = blr
            else:
                curColor = 'black'
                burColor = '#cfd2d2'
            
            stringff += '<tr>'
            stringff += '<td style="font-family:verdana;font-size:16;font-weight:bold;background-color:'+burColor+';color:'+curColor+'" >' + line + '</td>'
            stringff += '<td style="font-family:verdana;font-size:16;font-weight:bold;background-color:'+burColor+';color:'+curColor+'">' + str(B[line]) + ' %</td>'
            stringff += '</tr>'
            
        stringff += '</table>'
        
        return stringff

    def blockWisePossibleBit(self,total,B1,B2,B3,strr):



        bit_ifElse = self.calculatePercentage(B1,total,strr)
        bit_Loop = self.calculatePercentage(B2,total,strr)
        bit_Function = self.calculatePercentage(B3,total,strr)

        self.ShowTheTableOfPercentage(bit_ifElse,bit_Loop,bit_Function)
        

    def ShowTheTableOfPercentage(self,b1,b2,b3):
        #print(b1)
        
        Highest_ifElse = self.calculateHighestPercentageBlock(b1)
        Highest_Loop = self.calculateHighestPercentageBlock(b2)
        Highest_Function = self.calculateHighestPercentageBlock(b3)

        stringff = "<html><body><code>\n"
        stringff += self.tableMaking(b1,'If-ElseIf-Else Operations',"green","#7bc8ff",Highest_ifElse)
        stringff += self.tableMaking(b2,'Loop Operations',"red","#5cffee",Highest_Loop)
        stringff += self.tableMaking(b3,'Function Operation',"blue","#f6ff16",Highest_Function)
        stringff += "</code></body></html>\n"

        f = open("report.html", "w")
        f.write(stringff)
        f.close()

        
        


    
      
        



