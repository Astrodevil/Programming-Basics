#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct  node
{
	int data;
	struct node* link;
};
struct node* list1=NULL;
struct node* list2=NULL;
void display(struct node* root,int n)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node* p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}
int main()
{
	int x,y,value, s1=0,s2=0,i,j,l,d;

	printf("\nSize of 1st linked list: ");
	scanf("%d",&x);
	printf("Enter data of 1st linked list: ");
	for(i=x-1;i>=0;i--)
	{
		scanf("%d",&value);
		s1+=value*pow(10,i);
		display(list1,value);
	}
	printf("\n");
	printf("Size of 2nd linked list: ");
	scanf("%d",&y);
	printf("Enter data of 2nd linked list: ");
	for(i=y-1;i>=0;i--)
	{
		scanf("%d",&value);
		s2+=value*pow(10,i);
		display(list2,value);
	}
	printf("\n");
	if(s1 > s2)
	{
		d=s1-s2;
	}
	else
	{
		d=s2-s1;
	}
	l=(d==0)?1:log10(d)+1;
	int a[l];
	for(j=l;j>0;j--)
	{
		a[j]=d%10;
		d=d/10;
	}
	printf("Difference : ");
	for(j=1;j<=l;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n\n");
    return 0;
}
