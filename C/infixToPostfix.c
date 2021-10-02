#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 20
struct stack{
    int top;
    char arr[MAXSIZE];
};
void Push(struct stack *p,char ch)
{
    if(p->top==MAXSIZE-1)
        printf("Stack is full");
    else
        p->arr[++(p->top)]=ch;
}
char Pop(struct stack *p)
{
    if (p->top==-1)
        printf("Stack is empty");
    else
    {
        return p->arr[(p->top)--];
    }
}
int Precedence(char ch)
{
    if(ch=='^' || ch=='$' )
        return 3;
    else if(ch=='*' || ch=='/' || ch=='%')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='(')
        return 0;
}
void Create(struct stack *p)
{
    p->top=-1;
}
void main()
{
    char Infix[MAXSIZE],Postfix[MAXSIZE];
    int i=0,j=0,l;
    struct stack s;
    Create(&s);
    printf("Enter an infix expression:");
    scanf("%[^\n]s",Infix);
    l=strlen(Infix);
    Infix[l]=')';
    Infix[l+1]='\0';
    Push(&s,'(');
    while(Infix[i]!='\0')
    {
        if((Infix[i]>='A' && Infix[i]<='Z') || (Infix[i]>='a' && Infix[i]<='z'))
        {
            Postfix[j++]=Infix[i];
        }
        else if(Infix[i]=='(')
                    Push(&s,'(');
        else if(Infix[i]==')')
        {
            while(s.arr[s.top]!='(')
                      Postfix[j++]=Pop(&s);
                  Pop(&s);
        }
        else
        {
                while(Precedence(s.arr[s.top])>=Precedence(Infix[i]))
                    Postfix[j++]=Pop(&s);
                if(Precedence(s.arr[s.top])<Precedence(Infix[i]))
                    Push(&s,Infix[i]);
        }
        i++;
    }
    Postfix[j]='\0';
    printf("\nPostfix expression=%s",Postfix);
}
