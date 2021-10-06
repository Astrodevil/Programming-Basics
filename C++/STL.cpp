#include <bits/stdc++.h>
using namespace std;

void vectorDemo()
{

	/*->vectors are dynamic arrays ie expand size as per need automatically (2 times the previous size)
	->vectors store data in contiguos memory space*/

	//declare a vector
	//blank vector decleration (initial capacity-0)
	// vector<int> v;
	//vector with given size and itializing with a given value(initial capacity-size)
	// vector<int> v1(size,value);
	// vector with different values at different index
	// vector<int> vec = {22, 4, 5, 71, 9, 1, 13, 202, 45};
	// vector from another vector
	// vector<int> copied(vec)
	//vector functions
	// v.push_back(data);
	// v.pop_back(data)
	// sort(vec.begin(), vec.end());
	// bool present = binary_search(vec.begin(), vec.end(), 3);
	// cout << present << endl;

	// vector<int>::iterator itr;
	// one way to taker itr auto itr1 = upper_bound(vec.begin(), vec.end(), 13); //>x
	// auto itr2 = lower_bound(vec.begin(), vec.end(), 13);					  //>=x
	// for (int x : vec)
	// 	cout << x << " ";
}

void setsDemo()
{
	/*->stores data in sorted(ordered)/not sorted(unordered) order
	->stores unique data (order && unorder)
	->store duplicate(multiset)*/

	/*	
	unordered_set<string> s1;
	set<string> s1;
	s1.insert("A");
	s1.insert("B");
	s1.insert("C");
	s1.insert("D");
	for(auto x:s1)
	{
		cout<<x<<" ";
	}
	auto it=s1.find("B");
	if(it!=s1.end())
	{
		s1.erase(it);
	}
	
	
	multiset<int> s2;
	s2.insert(1);
	s2.insert(12);
	s2.insert(1);
	s2.insert(323);
	s2.insert(12);
	s2.insert(12);
	s2.insert(323);
	s2.insert(2);
	
	for(auto x:s2)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	auto it=s2.find(12);
	if(it!=s2.end())
	{
		s2.erase(it);
	}
	s2.erase(323);
		for(auto x:s2)
	{
		cout<<x<<" ";
	}
	*/
}

void mapsDemo()
{
	/*
	->unique data only	
	->data structure that stores data in (key,data) format
	ORDERED MAP
	->values are stored in sorted order according to keys
	->internal implementation by red black tree
	
	UNORDERED MAP
	->values are not stored in sorted order
	->internal implementation by hashing
	
	UNORDERED v/s ORDERED:
	1.inbuilt implementation
	2.time complexity(map-O(logN) unordered-O(1))
	3.valid key datatypes(can not use any datatype as key)
	*/

	/*	map<string,int> m1;
	
	for(int i=0;i<5;i++)
	{
		string s;
		cin>>s;
		m1[s]=i+1;
	}
	
	m1.insert(pair<string,int>("nishant",6));
	
	for(auto i:m1)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}
	
	auto itr=m1.find("nishant");
	if(itr==m1.end())
	{
		cout<<"MO VALUE\n";
	}
	else
	{
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	
//	m1.erase("nishant");
	m1.erase(itr);
	
	map<string,int> :: iterator it;
	for(it=m1.begin();it!=m1.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	
	unordered_map<string,int> m;
	for(int i=0;i<10;i++)
	{
		string s;
		cin>>s;
	//	m[s]=m[s]+1;
		m[s]++;
	}
	for(auto x:m)
	{
		cout<<x.first<<" "<<x.second<<endl;
	}*/
}

void arrayDemo()
{
	// Continuos memory allocation
	// Stores data of same type ie. if int then only int if char only char
	//static size ie not expand according to need automatically

	//initslize an array
	array<int, 5> arr = {1, 2, 3, 4, 5};

	//size of arr
	int size = arr.size();

	//printing arr
	for (auto x : arr)
	{
		cout << x << " ";
	}

	//check isEmpty
	int isEmpty = arr.empty();

	//find at index
	int pos = arr.at(2);

	//first and lsst element
	int first = arr.front();
	int last = arr.back();
}

void dequeDemo()
{
	//dynamic size and non continuos memory allocation
	deque<int> d;

	d.push_back(1);
	d.push_back(9);
	d.push_back(8);
	d.pop_back();
	d.pop_front();
	d.push_front(2);
	d.front();
	d.back();
	d.empty();
	d.erase(d.begin(), d.begin() + 1);

	for (auto i : d)
	{
		cout << i << " ";
	}
}

void listDemo()
{
	//implementaion doubly linked list
	//not direct access (have to traverse whole list)
	list<int> l;
	l.push_back(2);
	l.push_front(3);
}

void stackDemo()
{
	stack<string> s;
	s.push("hi");
	s.push("Hello");
	s.push("Hola");

	s.pop();
	s.size();
	s.empty();
}

void queueDemo()
{
	queue<string> q;
	q.push("hi");
	q.pop();
	q.size();
	q.empty();
}

void priorityQueueDemo()
{
	//max at Top
	priority_queue<int> maxAtTop;

	maxAtTop.push(2);
	maxAtTop.push(21);
	maxAtTop.push(1);
	maxAtTop.push(65);
	maxAtTop.push(24);

	// int n = maxAtTop.size();
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << maxAtTop.top() << " ";
	// 	maxAtTop.pop();
	// }

	//min at top
	priority_queue<int, vector<int>, greater<int>> minAtTop;
	minAtTop.push(10);
	minAtTop.push(100);
	minAtTop.push(1);
	minAtTop.push(5);
	minAtTop.push(50);

	int n = minAtTop.size();
	for (int i = 0; i < n; i++)
	{
		cout << minAtTop.top() << " ";
		minAtTop.pop();
	}
}

void algosDemo()
{
	// vector<int> vec = {1, 2, 3, 4, 5, 6};
	// vector<int>::iterator itr;
	// itr = find(vec.begin(), vec.end(), 4);

	// if (itr != vec.end())
	// {
	// 	cout << itr - vec.begin();
	// }

	//binary search
	// binary_search(dataType.begin(),dataType.end(),elementToSearch);

	//sorting
	//sort(dataType.begin(),dataType.end());

	//reverse string
	// reverse(string,begin(),string.end());
}

int main(void)
{
	algosDemo();
}
