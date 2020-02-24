import Utility
import copy

class Highlight_Executed_Statements:
    utility = None

    def __init__(self):

        self.utility = Utility.Utility() 
        print("Successful Highlighting Executed Statements")


    def getColorByRank(self, rank):
        if rank == 4:
            return "red"
        if rank == 3:
            return "orange"
        if rank == 2:
            return "blue"
        if rank == 1:
            return "#00d600"
        return "black"
        

    def highlightExecutedStatements(self, inputFileName):

        f2 = open(inputFileName)
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
                

        f3 = open('inputA.cpp')
        l3 = f3.read().splitlines()

        counter = 0
        stringfff = "<html><body><code>\n"

        for line in l3:
            counter = counter + 1

            if counter in range(1,4):
                continue

            if(line.startswith("#") or ('<' in line) or ('>' in line)):
                line = self.utility.Handeling_Html_Tag(line)

            if('freopen("Output.txt", "w+", stdout);' in line):
                line = '{'
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
                elif cc == 1:
                    stringfff += '<p style="font-family:verdana;font-weight:bold;color:'+curColor+'">' + line + '</p>\n'
                else:
                    stringfff += '<p style="font-family:verdana;font-weight:bold;color:'+curColor+'">' + line + '   //executed ' + str(cc) + ' times' + '</p>\n'    

            else:
                stringfff += '<p style="font-family:verdana;font-weight:bold;color:black">' + line + '</p>\n'
            
        stringfff += "</code></body></html>\n"

        f2.close()
        f3.close()
        f = open("ExecutedStatements.html", "w")
        f.write(stringfff)
        f.close()