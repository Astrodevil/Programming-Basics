#include<stdio.h>
void main()
{ 
    float a=0.0,r;
    char c;
  
  do{
    printf("Enter the Radius : ");
    scanf("%f",&r);
    a=3.14*r*r;
    printf("Area is %f",a);
    
    printf("\nDo you want to continue (Y/N)?");
    scanf(" %c", &c);
    
  }while (c=='y'|| c=='Y'); 
           
   printf("Thnak you!");
           
}
