/*
Project features:
1.Password consist of:
	->lowecase alphabet:a to z
	->uppercase alphabet:A to Z
	->number:0 to 9
	->special symbol:!,@,#,$,%,&

2.Password length:
	->Minimum:7
	->Maximum:100
	
3.Password begin with a 
letter (can be lowercase or uppercase)

4.Password  contain at least 
  2 lowercase letter , 2 uppercase letter,
  1 number , and 1 special symbol

5.Each time generated password is unique.

*/

#include<bits/stdc++.h>
using namespace std;

/*Select from which string set 
next char will be taken*/
/*Get value from 1 to 4
both included*/
int selectRandomSet(){
	srand(time(NULL));
	int k=rand()%5;
	if(k==0){
		k++;
	}
	return k;
}


/*Select index of element from the
list*/
/*Get value from 0 to 25 both included*/
int position(){
	srand(time(NULL));
	int z=rand()%26;
	return z;
}

/*Function to generate password*/
void getPass(int n) {
	string pass="";
	//All the strings to select from
	string s1 = "abcdefghijklmnopqrstuvwxyz";
	string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s3 = "!@#$%&";
	string s4 = "0123456789";
	//Variables to keep count for minimum requirements
	int upperCount=0,lowerCount=0,digitCount=0,specialCount=0,count=0,pos;
	while(count<n){
		pos=position();
		int selectSet=selectRandomSet();
		//For first char to be alphabet
		if(count==0){
			selectSet=2;
		}
		switch(selectSet){
			case 1:
				/*Ensure all requirements are fullfilled before inserting
				extra element of same type*/
				if(lowerCount==2 && (upperCount==0 || upperCount==1 || digitCount==0 || specialCount==0)){
					break;
				}
				lowerCount++;
				count++;
				pass+=s1[pos];
				break;
			case 2:
				if(upperCount==2 && (lowerCount==0 || lowerCount==1 || digitCount==0 || specialCount==0)){
					break;
				}
				upperCount++;
				count++;
				pass+=s2[pos];
				break;
			case 3:
				if(specialCount==1 && (lowerCount==0 || lowerCount==1 || digitCount==0 || upperCount==0 || upperCount==1)){
					break;
				}
				//pos modified for specific string size
				pos=pos%6;
				specialCount++;
				count++;
				pass+=s3[pos];
				break;
			case 4:
				if(digitCount==1 && (lowerCount==0 || lowerCount==1 || specialCount==0 || upperCount==0 || upperCount==1)){
					break;
				}
				pos=pos%10;
				digitCount++;
				count++;
				pass+=s4[pos];
				break;
		}
	}
	
	
	cout << "\n-----------------------------\n";
	cout << "         Password             \n";
	cout << "------------------------------\n\n";
	cout<<pass<<endl;
}


int main(void) {
	int t=1;
	while(t!=2) {
//Lable used to ensure no other input rather than int is used
lable1:
		cout << "\n-----------------------------\n";
		cout << "  Random Password Generator\n";
		cout << "------------------------------\n\n";
		cout << "    1. Generate Password"
		     << "\n";
		cout << "    2. Exit"
		     << "\n\n";
		cout << "Press key 1 to Generate Password and key 2 to exit  : ";
		cin>>t;
		/*In case user enters string or other input than int
		it will throw error and push back user to lable*/
		if(cin.fail()) {
			cout<<"Enter a valid choice :(\n";
			cin.clear();
			cin.ignore(256,'\n');
			goto lable1;
		}
		if(t==2) {
			break;
		} else if(t==1) {

			int n;
lable2:
			cout<<"Enter length of password : ";
			cin>>n;
			if(cin.fail()) {
				cout<<"Enter a valid choice :(\n";
				cin.clear();
				cin.ignore(256,'\n');
				goto lable2;
			}
			//Check whether password length input is correct or not
			if(n<7 || n>100) {
				cout<<"\nPassword length should vary between 7 to 100\n";
				goto lable2;
			}
			getPass(n);
		//In case of any other int value is entered except 1 and 2
		} else {
			cout<<"Enter a valid choice :(\n";
		}
	}
}

