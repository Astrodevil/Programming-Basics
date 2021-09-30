# First we define a variable "to_find" which contains the alphabet to be checked for in the file
# fo is the file which is to be read.


to_find="e"
fo = open('E:/file1.txt' ,'r+')
count=0

for line in fo:
    for word in line.split():
        if word.find(to_find)!=-1:
            count=count+1
                
print(count)
