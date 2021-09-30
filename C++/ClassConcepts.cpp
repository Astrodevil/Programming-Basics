#include<bits/stdc++.h>
using namespace std;

class Employee
{
	int id;
	float sal;
	string dept;
	string name;
	public:
		
	//default constructors
	Employee()
	{
		dept="General";
		sal=10000;
	}
	//paramterised constructor
	Employee(int x)
	{
		id=x;
	}
	
	Employee(int x,float y,string z)
	{
		id=x;
		sal=y;
		dept=z;
	}
	//copy constructors
	Employee(Emplyoee )&e)
	{
		id=e.id;
		sal=e.sal;
		dept=e.dept;
	}
	//Getters
	int getId()
	{
		return id;
	}
	float getSal()
	{
		return sal;
	}
	string getDept()
	{
		return dept;
	}
	
	string getName()
	{
		return name;
	}
	
	//Setters
	void setId(int x)
	{
		id=x;
	}
	void setSal(float x)
	{
		sal=x;
	}
	void setDept(string x)
	{
		dept=x;
	}
	void setName()
	{
		cin.ignore();
		getline(cin,name);
	}
	
	//functions
	void showDetails()
	{
		cout<<getId()<<" "<<getSal()<<" "<<getDept()<<" "<<getName()<<endl;
	}
	
};

int main(void)
{
	Employee e1,e2(3,23000,"Acc");
	e1.setId(1);
	e1.setName();
	e1.setSal(50000);
	e1.setDept("Engg");
	Employee e3=e1;
	e1.showDetails();
	e2.showDetails();
	e3.showDetails();
}

