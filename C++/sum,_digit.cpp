#include <bits/stdc++.h>
using namespace std;


int digit_sum(int n){
  if(n==0) return 0;
  return digit_sum(n/10)+(n%10);
}
int main(){
  int n;cin>>n;
  cout<<digit_sum(n);
}