#include<iostream>
using namespace std;

int main(){
int n,m;
cout<<" enter the rows and columns :  ";
cin>>n>>m;
int array[n][m];

for (int i=0;i<n;i++){  //rows
    for (int j=0;j<m;j++){ //columns
    cout<<" enter the array elements: "<<endl;

    cin>>array[i][j];
    }
}


int row_start=0;int row_end=n-1;int column_start=0;int column_end=m-1;
while(row_start<=row_end && column_start<=column_end)
{
    //for row start
    for (int col=column_start ;col<=column_end;col++){ 
        cout<<array[row_start][col]<<" ";
    }
    row_start++;
 //for column end
  for(int row= row_start; row<=row_end;row++)
  //{  //                
                                                                                 
      cout<<array[row][column_end]<<" ";                                                
  //}                                                                              
  column_end--;

//for row end

    
for (int col= column_end;col>=column_start;col--)
{        

    cout<<array[row_end][col]<<" ";

}
    //}

row_end--;

//for column_start
if(column_start<=column_end){
for (int row=row_end;row>=row_start;row--){
    cout<<array[row][column_start]<<" ";
}
}
column_start++;


}

return 0;


}
