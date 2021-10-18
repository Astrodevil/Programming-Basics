#include <stdio.h>
#include <math.h>
void main()
{
    int i,d,k,j=0,flag=0,c;
    double b,x,sum=0,s=0,a;
    printf("Enter a Binary fraction no:");
    scanf("%lf",&b);
    d=(int)b;
    for(i=b;i>0;i=i/10)
    {
        k=i%10;
        sum=sum+k*pow(2,j);
        ++j;
    }
    j=1;
    x=b-d;
    while(flag==0)
    {
        a=x*10;
        c=a;
        s=s+(c/pow(2,j++));
        x=a-c;
        if(j==6 || x==0)
            flag=1;
    }
    printf("Decimal fraction is %lf",sum+s);
}
