//tales only unique value 
// set returns value in sorted order
//unordered set returns in random order
#include<iostream>
#include<set>
using namespace std;
int main() {
	set<int>s;
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	for (auto &i : s) {
		cout << i << " ";
	}
	return 0;
}
