// Write a C program to check whether a character is alphabet or not

#include <stdio.h>

int main()
{
	char a;
	printf("Enter a character: ");
	scanf("%c",&a);
	printf("%c is ", a);
	if (((a>='a')&&(a<='z'))||((a>='A')&&(a<='Z')))
	{
		printf("an Alphabet");
	}
	else
	{
		printf("not an Alphabet");
	}
	printf("\n");
}

