import Utility

class Parenthesis_Balance:
    utility = None
    def __init__(self):
        self.utility = Utility.Utility() 
        print("Successful Parenthesis Balance")


    def TrackCalculation(self,inputFileName):
        f = open (inputFileName)
        #f = open ('pythonTest.txt')
        lines = f.read().splitlines()
        f.close()
        
        
        track_dict = {}
        test = 0
        no = 0
        stack=[]
        strr = ["start"]
        main_line_no = 0

        for z in lines:
            line = z.strip() #space removal
            no = no + 1
            if (line == 'int main()'):
                main_line_no = no 
            strr.append(line)

            
            if (self.utility.Loop_Check(line) or 
            self.utility.Function_Check(line) or
            self.utility.If_Check(line) or
            self.utility.Else_Check(line) or
            self.utility.ElseIf_Check(line) ) :
                test = 1
                continue
            
            if(test == 1):
                if(line=="{"):
                    stack.append(no)
                    continue

                elif(line=="}"):
                    idx = len(stack) - 1
                    start = stack[idx] - 1
                    end = no
                    status = self.utility.NonStatement_Declaration(strr[start])
                    track_dict[ start ] = (end,status)
                    stack.pop()

                    if(len(stack)!=0):
                        continue
                    else:
                        test = 0
                        #print(stack)
                        stack.clear()

        
        #print(track_dict)
        return track_dict,main_line_no

    def IfTrackCalculation(self,TrackOfBlock):

        if_dict = {}
        for i in TrackOfBlock.keys():
            if TrackOfBlock[i][1]  == "If":
                if_dict[i] = TrackOfBlock[i][0] 

        return if_dict


    def ElseTrackCalculation(self,TrackOfBlock):

        Else_dict = {}
        for i in TrackOfBlock.keys():
            if TrackOfBlock[i][1]  == "Else":
                Else_dict[i] = TrackOfBlock[i][0] 

        return Else_dict
    
    def ElseIfTrackCalculation(self,TrackOfBlock):

        ElseIf_dict = {}
        for i in TrackOfBlock.keys():
            if TrackOfBlock[i][1]  == "Else if":
                ElseIf_dict[i] = TrackOfBlock[i][0] 

        return ElseIf_dict

    def FunctionTrackCalculation(self,TrackOfBlock):

        Function_dict = {}
        for i in TrackOfBlock.keys():
            if TrackOfBlock[i][1]  == "Function":
                Function_dict[i] = TrackOfBlock[i][0] 

        return Function_dict

    def LoopTrackCalculation(self,TrackOfBlock):

        Loop_dict = {}
        for i in TrackOfBlock.keys():
            if TrackOfBlock[i][1]  == "Loop":
                Loop_dict[i] = TrackOfBlock[i][0] 

        return Loop_dict
    
    def LoopLeveling(self,loop_dict):
        
        loop_level = {}
        level = 0
        a = 0
        b = 0
        for i in sorted(loop_dict):
            c = i
            d = loop_dict[i]

            if(level == 0):
                level = 1
                loop_level[c] = (d,level)
            
            elif (d < b):
                level = level + 1
                loop_level[c] = (d,level)

            elif (d>b):
                level = 1
                loop_level[c] = (d,level)

            a = c
            b = d
        
        return loop_level


            
            

    
        