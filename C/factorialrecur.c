#include<stdio.h>
int main()
{
    int num,factorial;
    int fact_calc(int);
    printf("Enter a number:");
    scanf("%d",&num);
    factorial=fact_calc(num);
    printf("\n The factorial of number %d=%d",num,factorial);
    return 0;
}
int fact_calc(int n)
{
if (n==1)
return 1;
else
return n*fact_calc(n-1);
}