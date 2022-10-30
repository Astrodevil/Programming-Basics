// $$$$
// $$$$
// $$$$
// $$$$
// $$$$
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int rows,columns,i,j;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    
    cout<<"Enter the number of columns: ";
    cin>>columns;
     
     for(i=1; i<=rows; i++){
    for (j=1; j<=columns; j++){
        cout<<"$";
    }
    cout<<"\n";
}
getch();
    return 0;
}
