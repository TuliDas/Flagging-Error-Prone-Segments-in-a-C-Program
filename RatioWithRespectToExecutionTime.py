import Utility
import copy

class Ratio_Execution_Time:
    utility = None

    def __init__(self):

        self.utility = Utility.Utility() 
        print("Successfully Found Ration Corrssponding to Execution Time")

    def calculatePercentage(self,B,total,strr):
        
        E = {}

        for i in B:
            s=''
            for j in range(i[0],i[1]+1):
                s+= '<p>' + strr[j] + '</p>'
            E[s] = (B[i]/total) * 100
        return E


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

        stringff = '<table style="width:70%; border: 1px solid black;border-collapse: collapse;">'
        stringff+= '<caption style="font:italic;font-size:20;font-weight:bold;color:#2b20a1 ">' + title + '</caption>'
        
        stringff += '<tr>'
        stringff += '<th style = "font-size:18;" > Block </th>'
        stringff += '<th style = "font-size:18;"> Bit Percentage </th>'
        stringff += '</tr>'

        for line in B:
            if B[line] in H.values():
                curColor = clr
                burColor = blr
            else:
                curColor = 'black'
                burColor = '#cfd2d2'
            
            stringff += '<tr>'
            stringff += '<td style="border: 1px solid black;font-family:verdana;font-size:16;font-weight:bold;background-color:'+burColor+';color:'+curColor+'" >' + line + '</td>'
            stringff += '<td style="text-align: center;border: 1px solid black;font-family:verdana;font-size:16;font-weight:bold;background-color:'+burColor+';color:'+curColor+'">' + str(B[line]) + ' %</td>'
            stringff += '</tr>'
            
        stringff += '</table>'
        
        return stringff

    def blockWiseExecutionTimePercentage(self,total,E1,E2,E3,strr):
        
        
        E_ifElse = self.calculatePercentage(E1,total,strr)
        E_Loop = self.calculatePercentage(E2,total,strr)
        E_Function = self.calculatePercentage(E3,total,strr)
        self.ShowTheTableOfPercentage(E_ifElse,E_Loop,E_Function)

    def ShowTheTableOfPercentage(self,e1,e2,e3):
        #print(b1)
        
        Highest_ifElse = self.calculateHighestPercentageBlock(e1)
        Highest_Loop = self.calculateHighestPercentageBlock(e2)
        Highest_Function = self.calculateHighestPercentageBlock(e3)
        
        
        stringff = "<html><body><code>\n"
        if e1:
            stringff += self.tableMaking(e1,'If-ElseIf-Else Operations',"#9d0235","#7bc8ff",Highest_ifElse)    
        if e2:
            stringff += self.tableMaking(e2,'Loop Operations',"red","#5cffee",Highest_Loop)
        if e3:
            stringff += self.tableMaking(e3,'Function Operation',"blue","#f4fc76",Highest_Function)
        stringff += "</code></body></html>\n"

        f = open("reportExecute.html", "w")
        f.write(stringff)
        f.close()
