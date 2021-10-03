#read two lists a and b ,write a function that returns a list that contains only the elements that are common to both the lists.

a=[]
b=[]
newlist=[]

for i in a:
    if i in b:
        if i in newlist:
            continue
        newlist.append(i)
        
        
print(newlist)
