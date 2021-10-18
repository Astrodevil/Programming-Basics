#include <iostream>
using namespace std;

int main() {
	int tc;
	cin>>tc;
	for (int i = 0; i < tc; i++) {
	 
	 int noOfPrtcpnt;
	 cin>>noOfPrtcpnt;
	 int changeOfSpeedPerUnit;
	 cin>>changeOfSpeedPerUnit;
	 int maxDose;
	 cin>>maxDose;
	 int prtcpntSpeeds[noOfPrtcpnt-1];
	int frndSpeed;
	 for(int j=0;j<noOfPrtcpnt-1;j++){
	     cin>>prtcpntSpeeds[j];
	 }
	 cin>>frndSpeed;
	 int maxSpeed=prtcpntSpeeds[0];
	 for(int k=0;k<noOfPrtcpnt-1;k++){
	     if(prtcpntSpeeds[k]>maxSpeed){
	         maxSpeed=prtcpntSpeeds[k];
	     }
	 }
	 if(frndSpeed>maxSpeed){
	     cout<<"Yes"<<endl;
	 }
	 else{
	     if(changeOfSpeedPerUnit<0){
	         cout<<"No"<<endl;
	     }
	     else{
	         int incSpeed=frndSpeed+((maxDose-1)*changeOfSpeedPerUnit);
	         if(incSpeed>maxSpeed){
	             cout<<"Yes"<<endl;
	         }
	         else{
	             cout<<"No"<<endl;
	         }
	     }
	 }
	 

	}
	return 0;
}