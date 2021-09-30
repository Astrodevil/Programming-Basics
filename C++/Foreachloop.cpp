
#include <iostream>

using namespace std;

int main()
{
    
    int ArrayofFirstTenOddNumber[]={1,3,5,7,9,11,13,15,17,19};
    cout<<"elements of Array are:\t";
    //Foreach Loop to output elements of array
    for(int element:ArrayofFirstTenOddNumber)
    {
        cout<<element<<" ";
    }
    return 0;
}