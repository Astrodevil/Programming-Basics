//Finding an element in an array
#include<stdio.h>
void main()
{
  int a[25],size,k,i,c=0;
  printf("Enter the size of the array\t");
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
     printf("\nEnter the %d element\t",i+1);
     scanf("%d",&a[i]);
   }
  printf("Enter the element to find in an array\t");
  scanf("%d",&k);
  for(i=0;i<size;i++)
  {
    if(a[i]==k)
     {
       c++;
     } 
  }
  if(c>=1)
  {
   printf("Element %d is present",k);
   }
  else if(c==0)
    printf("Element %d is not present",k);

}
