print("Note that facotrial are of only +ve integers including zero\n")

#function of facorial
def factorial_of(number):
    mul=1
    for i in range(1,num+1):
        mul=mul*i
    return mul
    

#take input of the number
num=int(input("Enter the number you want the fatcorial of:"))

#executing the function
if num<0 :
    print("Not possible")
else:
    print("Factorial of ",num," is ",factorial_of(num))

