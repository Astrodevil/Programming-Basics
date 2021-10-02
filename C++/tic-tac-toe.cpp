#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

char mat[3][3]={'1','2','3','4','5','6','7','8','9'};
char player='X';

int n;
class game
{
public:
//FUNCTION 0 
void clear() 
{
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
mat[i][j]=5;//If you want you can change this to the above one '1','2' by manually placing these values at each index od array
}
}
player='X';
n=0;
}
//FUNCTION 1
void draw()
{
//system("cls");
for (int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<"   "<<mat[i][j]<<"   ";
}
cout<<endl;
}
}
//FUNCTION 2
void input()
{
int a;
cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
cout<<"   It's "<<player<<" Turn !\n   Press Any Number Where You want To Mark: ";
cin>>a;
cout<<"\n";
//fOR 1
if(a==1)
{
if(mat[0][0]!='X'&&mat[0][0]!='O')
{
mat[0][0]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
//FOR 2
if(a==2)
{
if(mat[0][1]!='X'&&mat[0][1]!='O')
{
mat[0][1]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
    //FOR 3
if(a==3)
{
if(mat[0][2]!='X'&&mat[0][2]!='O')
{
mat[0][2]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
//FOR 4
if(a==4)
{
if(mat[1][0]!='X'&&mat[1][0]!='O')
{
mat[1][0]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
    //FOR 5
     if(a==5)
{
if(mat[1][1]!='X'&&mat[1][1]!='O')
{
mat[1][1]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
}
//FOR 6
 
if(a==6)
{
if(mat[1][2]!='X'&&mat[1][2]!='O')
{
mat[1][2]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
//FOR 7
   if(a==7)
{
if(mat[2][0]!='X'&&mat[2][0]!='O')
{
mat[2][0]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
    //FOR 8
    if(a==8)
{
if(mat[2][1]!='X'&&mat[2][1]!='O')
{
mat[2][1]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
    //FOR 9
if(a==9)
{
if(mat[2][2]!='X'&&mat[2][2]!='O')
{
mat[2][2]=player;
}
else
{
cout<<"Try Again!\n";
input();
}
 
    }
}
//FUNCTION 3
void player2()
{
if(player=='X')
player='O';
else
player='X';
}
//FUNCTION 4
char win()
{
if(mat[0][0]=='X' && mat[0][1]=='X' && mat[0][2]=='X' )
return 'X';
 
if(mat[1][0]=='X' && mat[1][1]=='X' && mat[1][2]=='X' )
    return 'X';
 
if(mat[2][0]=='X' && mat[2][1]=='X' && mat[2][2]=='X' )
return 'X';
 
if(mat[0][0]=='X' && mat[1][0]=='X' && mat[2][0]=='X' )
    return 'X';
 
if(mat[0][1]=='X' && mat[1][1]=='X' && mat[2][1]=='X' )
return 'X';
 
if(mat[0][2]=='X' && mat[1][2]=='X' && mat[2][2]=='X' )
    return 'X';
 
if(mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X' )
    return 'X';
 
if(mat[2][0]=='X' && mat[1][1]=='X' && mat[0][2]=='X' )
return 'X';
 
   if(mat[0][0]=='O' && mat[0][1]=='O' && mat[0][2]=='O' )
return 'O';
 
if(mat[1][0]=='O' && mat[1][1]=='O' && mat[1][2]=='O' )
return 'O';
 
if(mat[2][0]=='O' && mat[2][1]=='O' && mat[2][2]=='O' )
return 'O';
 
if(mat[0][0]=='O' && mat[1][0]=='O' && mat[2][0]=='O' )
   return 'O';
 
if(mat[0][1]=='O' && mat[1][1]=='O' && mat[2][1]=='O' )
return 'O';
 
if(mat[0][2]=='O' && mat[1][2]=='O' && mat[2][2]=='O' )
return 'O';
 
if(mat[0][0]=='O' && mat[1][1]=='O' && mat[2][2]=='O' )
return 'O';
 
if(mat[2][0]=='O' && mat[1][1]=='O' && mat[0][2]=='O' )
return 'O';
 
return ('/');
 
}
 
};
int main()
{
game g1;
    do{
     cout<<"      X-O-X-O-X \n";
     cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
cout<<"   | TIC TAC TOE |\n";
cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
n=0;
g1.clear();
     g1.draw();
    while(1)
    {
     n++;
     g1.input();
     g1.draw();
     if(g1.win()=='X')
     {
     cout<<"Player 1 Won!\n"<<endl;
     break;
}
else if(g1.win()=='O')
     {
     cout<<"Player 2 Won!\n"<<endl;
     break;
}
else if(g1.win()=='/' && n==9)
     {
     cout<<"Draw!\n"<<endl;
     break;
}
g1.player2();
}
cout<<"Do You Want To Play Again? press (y/n)";
//system("pause");
}
while(getche()=='y');
}
