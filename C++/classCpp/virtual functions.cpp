//virtual function
#include<bits/stdc++.h>
using namespace std;

class Animals{
	public:
		virtual void setName(string name)
		{
			
		}
		
		virtual void setVoice(string voice)
		{
			
		}
		virtual void setColour(string colour)
		{
			
		}
		virtual void getDetails()
		{

		}
};

class Dogs:public Animals{
	private:
		string name,voice,colour;
	public:
		void setName(string name)
		{
			this -> name = name;
		}
		
		void setVoice(string voice)
		{
			this -> voice = voice;
		}
		void setColour(string colour)
		{
			this -> colour = colour;
		}
		void getDetails()
		{
			cout<<"\nName of Dog is : "<<name<<"\nVoice of Dog is : "<<voice<<"\nColour of Dog is : "<<colour;
		}
};

class Cats:public Animals{
	private:
		string name,voice,colour;
	public:
		void setName(string name)
		{
			this -> name = name;
		}
		
		void setVoice(string voice)
		{
			this -> voice = voice;
		}
		void setColour(string colour)
		{
			this -> colour = colour;
		}
		void getDetails()
		{
			cout<<"\nName of Cat is : "<<name<<"\nVoice of Cat is : "<<voice<<"\nColour of Cat is : "<<colour;
		}
};

int main(void)
{
/*	Animals* a;
	a=new Dogs();
	a -> legs();
	Animals* b;
	b=new Cats();
	b -> displayName();
	Animals* c;
	c=new Animals();
	c -> displayName();*/
	
	int n,i=0;
	cout<<"Enter how many animals : ";
	cin>>n;
	string check,name,voice,colour;
	vector<Animals*> vec(n);
	while(n)
	{
		cout<<"\nEnter animal (dog/cat) : ";
		cin>>check;
		if(check=="dog")
		{
			vec[i]=new Dogs();
		}
		else if(check=="cat")
		{
			vec[i]=new Cats();
		}
		else
		{
			cout<<"\nEnter valid animal";
			continue;
		}
		cout<<"\nEnter name : ";
		cin>>name;
		vec[i] -> setName(name);
		cout<<"\nEnter colour : ";
		cin>>colour;
		vec[i] -> setColour(colour);
		cout<<"\nEnter voice : ";
		cin>>voice;
		vec[i] -> setVoice(voice);
		i++;
		n--;
	}
	cout<<"\nAnimal Details:\n";
	for(i=0;i<vec.size();i++)
	{
		vec[i]->getDetails();
	}
}

