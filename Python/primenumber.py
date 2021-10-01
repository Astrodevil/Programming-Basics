
def primeNumber(n):
    if (n==2):
        return True
    if n==1  or n%2==0:
        return False
    i=2
    while i*i<=n:
        if n%i==0:
            return False
        i+=1
    return True
if __name__=="__main__":
    n=int(input(""))
    if primeNumber(n):
        print(f"{n} is a prime number")
    else:
        print(f"{n} is not a prime number")