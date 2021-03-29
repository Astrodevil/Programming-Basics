#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    public:
    int x;
    private:
    int z;
};

class B: public A
{
    public:
    int y;
};
int main()
{
    B obj1;
    obj1.x=10;
    obj1.y=20;
    cout<<"Values:"<<obj1.x<<obj1.y;
    return 0;
};