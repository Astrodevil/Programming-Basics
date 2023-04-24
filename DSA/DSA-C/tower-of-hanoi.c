#include <stdio.h>
 
void towers(int num, char fromtower, char totower, char auxtower);
 
int main()
{
    int num;
 
    printf("\nEnter the number of disks : ");
    scanf("%d", &num);
    printf("\nThe sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    printf("\n\n*** The disks are successfully shifted from tower A to tower C ***\n\n");
    return 0;
}
void towers(int num, char fromtower, char totower, char auxtower)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", fromtower, totower);
        return;
    }
    towers(num - 1, fromtower, auxtower, totower);
    printf("\n Move disk %d from tower %c to tower %c", num, fromtower, totower);
    towers(num - 1, auxtower, totower, fromtower);
}
