//            *
//          *   *
//        *   *   *
//      *   *   *   *
//    *   *   *   *   *
#include<stdio.h>
#include<conio.h>
void main()
{
    int row,col,h;
    printf("enter height\n");
    scanf("%d",&h);
    if(h%2!=0)
    {
        for(row=0;row<h;row++)
        {
           for(col=1;col<(2*h);col++)
           {
               if((col>=h-row)&&(col<=h+row) || (col>h-row)&&(col<h+row))
                {
                    if(((col%2==0)&&(row%2==0))||((col%2!=0)&&(row%2!=0)))
                    {
                        printf("  ");
                    }
                    else if(col==row)
                    {
                        printf("* ");
                    }
                    else{
                        printf("* ");
                    }
                }
               else
                {
                    printf("  ");
                }  
           }
        printf("\n"); 
        }
    }
    else
    { 
        for(row=1;row<=h;row++)
        {
           for(col=1;col<(2*h);col++)
           {
               if((col>h-row)&&(col<h+row))
                {
                    if(((col%2==0)&&(row%2==0))||((col%2!=0)&&(row%2!=0)))
                    {
                        printf("  ");
                    }
                    else if(col==row)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("* ");
                    }
                }
               else
                {
                    printf("  ");
                }  
           }
        printf("\n"); 
        }

    }
}
