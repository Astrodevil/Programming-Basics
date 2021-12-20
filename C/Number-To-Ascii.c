#include <stdio.h>

int main() 
{
    int num;
    printf("Please insert a number between 0 and 255 [0-255]: ");
    scanf("%d",&num);

    if(num >= 0 && num <= 255)
    {

        printf("\n The number %d in ASCII is %c \n",num,num);

    }
    else{

        printf("The selected number is not between 0 and 255, please try again. \n");

    }


    return 0;
}