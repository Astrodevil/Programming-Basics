#include <iostream>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	for (int i = 0; i < tc; i++) {
	 
	 int noOfY=0;
	 int noOfN=0;
	 for(int i=0;i<3;i++){
	     int x;
	     cin>>x;
	     if(x==0){
	         noOfN++;
	         
	     }
	     else if(x==1){
	         noOfY++;
	     }
	 }
	 int noOfAY=0;
	 int noOfAN=0;
	 for(int i=0;i<3;i++){
	     int x;
	     cin>>x;
	     if(x==0){
	         noOfAN++;
	         
	     }
	     else if(x==1){
	         noOfAY++;
	     }
	 }
	 if(noOfY==noOfAY&&noOfN==noOfAN){
	     cout<<"Pass"<<endl;
	     
	 }
	 else{
	     cout<<"Fail"<<endl;
	 }
	}
	return 0;
}