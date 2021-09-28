//Polymorphism
#include<bits/stdc++.h>
using namespace std;

//function overloading
class Func{
	public:
		void func1()
		{
			cout<<"This is function 1"<<endl;
		}
		void func1(int x)
		{
			cout<<"This is function 2"<<endl;
		}
		void func1(string s)
		{
			cout<<"This is function 3"<<endl;
		}
};


//operator overloading
class Employee{
	private:
	int sal,id;
	string dept;
	public:
		Employee()
		{
			sal=0;
			id=0;
			dept="";
		}
		Employee(int s,int i,string d)
		{
			sal=s;
			id=i;
			dept=d;
		}
		bool operator== (Employee a)
		{
			if(sal==a.sal && id==a.id && dept==a.dept)
			{
				return true;
			}
			return false;
		}
};

//virtual functions
class Parent{
	public:
		void test1()
		{
			cout<<"This is parent class function 1\n";
		}
		virtual void test2()
		{
			cout<<"This is parent class function 2\n";
		}
};

class Child : public Parent{
	public:
		void test1()
		{
			cout<<"This is child class function 1\n";
		}
		void test2()
		{
			cout<<"This is child class function 2\n";
		}
};

int main(void)
{
	/*
	//function overloading
	
	Func f;
	f.func1();
	f.func1(3);
	f.func1("Hello");
	
	
	//operator overloading
	Employee e1,e2(100000,1,"Hello"),e3(100000,1,"Hello");
	if(e1==e2)
	{
		cout<<"Same eployee\n";
	}
	else
	{
		cout<<"Different eployee\n";
	}
	if(e3==e2)
	{
		cout<<"Same eployee\n";
	}
	else
	{
		cout<<"Different eployee\n";
	}
*/
	//virtual function;
	Child c;
	Parent *ptr;
	ptr=&c;
	ptr -> test1();
	ptr -> test2();
}

