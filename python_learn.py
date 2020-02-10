str = "include<bits>"
test = "abc"
for i in str:

    if(i=='<' or i=='>'):
        test = test + i
        test= test + ' '
    else:
        test = test + i
        
print(test)