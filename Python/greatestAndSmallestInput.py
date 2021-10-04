n = int(input("please enter the number of inputs => "))
s=0
for a in range(0,n):
    s = int(input("please enter a number => "))
    d = s
    if a == 0:
      m=s
      g=s
      largest = m
      smallest = g
    #m = s
    if d > m:
        largest = d
        m = d
    if d < g:
      smallest = d
      g = d

    #print(s)

if n>0:
    print("largest  => ",largest)
    print("smallest =>",smallest)
