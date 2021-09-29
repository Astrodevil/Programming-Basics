#include <bits/stdc++.h>
using namespace std;
//oops is used to provide bug free environment
//structure is not safe as it can be accessed anywhere in c proramme.We cannot add function insde structure but can be defined in class.

class employee
{
    private:
        int a,b,c;
    public:
        int d,e;
        void setdata(int a1,int b1,int c1);//declaration
        void getdata(){
            cout<<"the value of a is"<<a<<endl;
            cout<<"the value of b is"<<b<<endl;
            cout<<"the value of c is"<<c<<endl;
            cout<<"the value of d is"<<d<<endl;
            cout<<"the value of e is"<<e<<endl;
        }
}; 

void employee::setdata(int a1,int b1,int c1){
    a=a1;
    b=b1;
    c=c1;

}

int main()
{
    employee steve;
    // steve.a=36; it is private
    steve.d=34;
    steve.e=89;
    steve.setdata(1,2,4);
    steve.getdata();
    return 0;
}