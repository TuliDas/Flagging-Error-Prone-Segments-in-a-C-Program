import Utility
import copy

class Highlight_Heuristics:
    utility = None

    def __init__(self):

        self.utility = Utility.Utility() 
        print("Successful Highlighting Heuristics")


    def getColorByRank(self, heuristics_num):
        if heuristics_num == 1:
            return "red"
        if heuristics_num == 2:
            return "orange"
        if heuristics_num == 3:
            return "blue"
        
        return "black"
        

    def highlightingHeuristics(self, inputFileName,H1,H2,H3):

        f3 = open(inputFileName)
        l3 = f3.read().splitlines()

        counter = 0
        stringfff = "<html><body><code>\n"
        for line in l3:

            counter = counter + 1

            if counter == 1:
                continue

            if(line.startswith("#") or ('<' in line) or ('>' in line)):
                line = self.utility.Handeling_Html_Tag(line)

            if('freopen("Output.txt", "w+", stdout);' in line):
                line = '{'

            elif ((counter in H1) or (counter in H2) or (counter in H3)):
                if counter in H1:
                    curColor = "green"
                    burColor = "#7bc8ff"

                if counter in H2:
                    curColor = "red"
                    burColor = "#5cffee"

                if counter in H3:
                    curColor = "blue"
                    burColor = "#f6ff16"
            else:
                curColor = "black"
            

            if curColor == "black":
                stringfff += '<p style="font-family:verdana;font-weight:bold;color:'+curColor+'">' + line + '</p>\n'
            else:
                stringfff += '<p style="font-family:verdana;font-size:20;font-weight:bold;background-color:'+burColor+';color:'+curColor+'">' + line +  '</p>\n'

        stringfff += "</code></body></html>\n"

    
        f3.close()
        f = open("heuristics.html", "w")
        f.write(stringfff)
        f.close()








