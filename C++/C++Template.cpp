//Templates are used to create generic classes in C++
#include <iostream>

using namespace std;
template<class T>
class Maths
{
    T num1,num2;
    public:
    void init(T num1,T num2)
    {
        this->num1=num1;
        this->num2=num2;
    }
    T add()
    {
        T result=num1+num2;
        return result;
    }
    T subtract()
    {
        T result=num1-num2;
        return result;
    }
    T multiply()
    {
        T result=num1*num2;
        return result;
    }
    float divide()
    {
        float result=num1/num2;
        return result;
    }
    T modulo()
    {
        T result = num1%num2;
        return result;
    }
    
};

int main()
{
    //Creating Object of  Maths class with values of type int
    int a,b;
    cout<<"Enter 2 numbers of type int"<<endl;
    cin>>a>>b;
    Maths<int> m;//We have to specify datatype while creating object of generic class
    m.init(a,b);
    cout<<"Result is \nAddition:\t"<<m.add()<<"\nSubtraction:\t"<<m.subtract()<<"\nMultiplication:\t"
    <<m.multiply()<<"\nDivision:\t"<<m.divide()<<endl;
    //Creating Object of  Maths class with values of type float
    float a1,b1;
    cout<<"Enter 2 numbers of type float"<<endl;
    cin>>a1>>b1;
    Maths<float> m1;//We have to specify datatype while creating object of generic class
    m1.init(a1,b1);
    cout<<"Result is \nAddition:\t"<<m1.add()<<"\nSubtraction:\t"<<m1.subtract()<<"\nMultiplication:\t"
    <<m1.multiply()<<"\nDivision:\t"<<m1.divide()<<endl;
    
    return 0;
}
