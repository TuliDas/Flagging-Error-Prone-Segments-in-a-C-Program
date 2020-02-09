
ttt = "int add(int a,int b);"
ttt1 = "int a;"

word = ttt.split()

if ( ('(' in ttt1) and (')' in ttt1) and ( word[0]=="int" or word[0]=="float" or word[0]=="double" or   )   ):
    print("YES")
else:
    print("NO")
