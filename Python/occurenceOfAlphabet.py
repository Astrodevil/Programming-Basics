# Counts the number of times the alphabet defined as "inp"
# occurs in the string "str1"


str1 = input("pls input string  =>")
inp = input("character  =>")
x=len(str1)
sumd=0
for i in range(0,x):
    if str1[i]==inp:
        sumd=sumd+1
print("No. of ocurences =",sumd)
