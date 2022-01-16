// Write a C program to check whether a number is negative, positive or zero

#include <stdio.h>

int main()
{
	int num;
	printf("Enter a number: ");
	scanf("%d",&num);
	printf("The entered number '%d' is ",num);
	if (num>0)
	{
		printf("positive!");
	}
	else if (num<0)
	{
		printf("negative!");
	}
	else
	{
		printf("zero!");
	}
}


