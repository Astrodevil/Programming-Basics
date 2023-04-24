// I will be creating a SWITCH script example, a switch can be used instead of if...else statements to optimize the code.

#include <stdio.h>

int main()
{
    int selectedNum;
    printf("Please select a number between [1-10] and it will be printed on the screen.");
    scanf("%d",&selectedNum);

    switch (selectedNum)
    {
    case 1:
        printf("The selected number was 1");
        break;
    case 2:
        printf("The selected number was 2");
        break;
    case 3:
        printf("The selected number was 3");
        break;
    case 4:
        printf("The selected number was 4");
        break;
    case 5:
        printf("The selected number was 5");
        break;
    case 6:
        printf("The selected number was 6");
        break;
    case 7:
        printf("The selected number was 7");
        break;
    case 8:
        printf("The selected number was 8");
        break;
    case 9:
        printf("The selected number was 9");
        break;
    case 10:
        printf("The selected number was 10");
        break;

    
    default:
        printf("The selected number is not between 0 and 10.");
        break;
    }

}


// another alternative to this script would be checking if selectedNum is bigger or equal to 1 and smaller or equal to 10.