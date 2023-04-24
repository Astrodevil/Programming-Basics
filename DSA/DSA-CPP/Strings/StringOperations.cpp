#include<bits/stdc++.h>
using namespace std;

int main()
{
  //0
  string s;
  cin >> s;
  cout << s << endl;
  
  //1
  //inserting a line from sentence
  fflush(stdin);
  getline(cin, s);
  cout << s << endl;
  
  //2
  //string properties
  s.push_back('o')
  cout << s << endl;
  
  //3
  s.pop_back()
  cout << s << endl;
  
  //4
  cout << "Strign length: " << s.length() << endl;
  cout << strlen(s) << endl;  //C language style, works in case of character array
  
  //5
  string s2;
  cin >> s2;
  cout << s2 << endl;
  s.copy(s2, 5);
  cout << s << " " << s2 << endl;
  
  //6
  char s1[] = "string 1";
  char S[] = "string 2";
  strcpy(s1, s2);
  cout << s1 << " " << S << endl;
  
  //7
  int cmp = strcmp(s1, S);
  cout << cmp;
  cout << s1 << " " << S << endl;  
  
  //8
  char s1[] = "string 1";
  char s2[] = "str";
  cout << strstr(s1, S);
  cout << strcat(s1, s2);
  
  //9
  char s1[] = "string 1";
  char s2[] = "ing";
  string s = "google";
  s.copy(s1, 3);
  cout << s << " " << s1 << endl;

}
