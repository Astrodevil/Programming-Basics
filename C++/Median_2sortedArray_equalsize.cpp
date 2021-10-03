#include<iostream>
using namespace std;
void merge(int a[],int b[],int l1,int mergearr[]){
    int i=0,j=0,k=0;
    while(i<l1 && j<l1){
        if (a[i]<b[j])
            {
                mergearr[k++]=a[i++];
            }
            else
            {
                mergearr[k++]=b[j++];
            }

    }
 while (i<l1)
{
    mergearr[k++]=a[i++];
   
}
        while(j<l1)
        {
            mergearr[k++]=b[j++];
        }
}

int median( int a[],int l){
    int medn;
if(l%2==0){
    int an=l/2;
    int bn=(l/2)+1;
    int first=a[an-1];
    int second=a[bn-1];
    cout<<"first median "<<a[an-1]<<endl;
    cout<<"second median "<<a[bn-1]<<endl;
  medn =(first+second)/2;
  return medn;
}
else{
int median=(l+1)/2;
medn=a[median-1];
return medn;
}
}

int main(){
int mergearr[6];
int a[]={6,7,8};
int b[]={1,2,3};
merge(a,b,6,mergearr);
cout<<"merge array "<<endl;
for(int i=0;i<6;i++){
    cout<<mergearr[i]<<endl;
}
cout<<" Final median is "<<median( mergearr,6)<<endl;
    return 0;
}
