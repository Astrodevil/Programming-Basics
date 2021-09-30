-=EndlessGamer=-
#6640
man strings

PwincessPatty — Today at 7:36 PM
when is hacktober
time
-=EndlessGamer=- — Today at 7:36 PM
no idea
PwincessPatty — Today at 7:37 PM
laters ma
send your profile
ill read it when im free
-=EndlessGamer=- — Today at 7:37 PM
insta?
PwincessPatty — Today at 7:37 PM
on whatsapp
no
the thing u got
your type
ka page
i found it
i goes
PwincessPatty
 started a call.
 — Today at 9:26 PM
PwincessPatty — Today at 9:26 PM
hereee
ya tell
-=EndlessGamer=- — Today at 9:27 PM
https://github.com/issues?page=5&q=is%3Aopen+is%3Aissue+label%3Ahacktoberfest
find what you can do in this
and type Can you assign this issue to me?
PwincessPatty — Today at 9:29 PM
im supposed to do that uh
-=EndlessGamer=- — Today at 9:29 PM
ya
PwincessPatty — Today at 9:29 PM
https://github.com/sushish-kumar/cpp-hacktoberfest
GitHub
GitHub - sushish-kumar/cpp-hacktoberfest: Aimed to give a positive ...
Aimed to give a positive overview of open source development. - GitHub - sushish-kumar/cpp-hacktoberfest: Aimed to give a positive overview of open source development.

did it start at 8:30
-=EndlessGamer=- — Today at 9:30 PM
ya
PwincessPatty — Today at 9:31 PM
why u no tel
-=EndlessGamer=- — Today at 9:31 PM
idk
PwincessPatty — Today at 9:31 PM
did u find anything
-=EndlessGamer=- — Today at 9:31 PM
ive asked to get it assigned
PwincessPatty — Today at 9:31 PM
can u see that git i sent u
-=EndlessGamer=- — Today at 9:31 PM
ya
PwincessPatty — Today at 9:31 PM
im not understanding
-=EndlessGamer=- — Today at 9:32 PM
just add some cpp file and send a PR
lets see if he accepts it
PwincessPatty — Today at 9:32 PM
feel like itll get rejected though
cuz that git has been used only for hacktober
-=EndlessGamer=- — Today at 9:32 PM
ya so?
PwincessPatty — Today at 9:32 PM
idkk
-=EndlessGamer=- — Today at 9:32 PM
there are contributers
just add
we'll see
PwincessPatty — Today at 9:33 PM
what do i habb
more than two rejections and ill be banned ;-;
forever
-=EndlessGamer=- — Today at 9:33 PM
forever uh
PwincessPatty — Today at 9:33 PM
it said indefinetly
can u find something for mee 🥺
might be able to do simple html also
-=EndlessGamer=- — Today at 9:35 PM
wait
take merge sort
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& array, int startL, int endL, int startR, int endR) {
  vector<int> left(array.begin() + startL, array.begin() + endL + 1);
  vector<int> right(array.begin() + startR, array.begin() + endR + 1);
  int mergeArrayStart = startL, leftIndex = 0, rightIndex = 0;
Expand
mergeSort.cpp
2 KB
PwincessPatty — Today at 9:36 PM
oh
i went to the java thing
he has a java repo too
i hab java programs
from DAA lab
fine ill take merge
where should i put the file
cuz the readme says do a hello world one
in the hello world folder
-=EndlessGamer=- — Today at 9:38 PM
then do hello world?
PwincessPatty — Today at 9:40 PM
in the commit
Image
first is title
and next is message no
-=EndlessGamer=- — Today at 9:40 PM
yeah, dont worry about commits
PwincessPatty — Today at 9:42 PM
https://github.com/C-Lite/Competitive-Programming-Algos/issues/6
GitHub
Add National Dutch Flag Algo · Issue #6 · C-Lite/Competitive-Progra...
Three part sorting is done using Dutch National Flag Algorithm, Explain with comments and write code for it

how to do
im supposed to ask uh
-=EndlessGamer=- — Today at 9:42 PM
yeah tag him and ask
PwincessPatty — Today at 9:43 PM
in the comment?
-=EndlessGamer=- — Today at 9:43 PM
ya
PwincessPatty — Today at 9:44 PM
how will ik if i get assigned?
-=EndlessGamer=- — Today at 9:44 PM
youll get mail or itll be in notifs
PwincessPatty — Today at 9:44 PM
this is diff than last time no
thatsss whyy youre in charge of repo
-=EndlessGamer=- — Today at 9:45 PM
no
PwincessPatty — Today at 9:45 PM
thatss why u hab work this timee
-=EndlessGamer=- — Today at 9:45 PM
no
PwincessPatty — Today at 9:45 PM
u hab to assign and all no
wheres the code even
Image
also should i ask
considering someone already has
-=EndlessGamer=- — Today at 9:47 PM
if someone has, then leave
PwincessPatty — Today at 9:48 PM
should i?
Image
-=EndlessGamer=- — Today at 9:48 PM
what does he mean by material tho
PwincessPatty — Today at 9:49 PM
that person has put up soo many like that
can i do this?
Image
am i being annoying?
-=EndlessGamer=- — Today at 9:52 PM
nu
PwincessPatty — Today at 9:52 PM
ull help noo
-=EndlessGamer=- — Today at 9:52 PM
okk
PwincessPatty — Today at 9:52 PM
seems easyy
idk
it is noo
i am labourer
in this IT field
i am still labourer
havent become contractor yet
wee i got one
-=EndlessGamer=- — Today at 9:55 PM
haw
PwincessPatty — Today at 9:56 PM
dutch national flag algo
idk it
-=EndlessGamer=- — Today at 9:56 PM
wish my company's repo was in hacktoberfest
PwincessPatty — Today at 9:56 PM
lol
now now
f
idk the thing only
yaa
help
how do i even do it?
where od i go
how do i do it
-=EndlessGamer=- — Today at 9:57 PM
/* 6.01 Dutch National Flag */ 

#include <iostream>
#include <string>
#include <vector> 


using namespace std; 


void print_vector(vector<int> A){
    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " "; 
    
    }
    cout << endl ;
}
vector<int> sort(int pivot_index, vector<int> A){
    int pivot = A[pivot_index]; 
    int n = A.size(); 
    //structure as follows
    //bottom group : 0..smaller-1
    //middle group : smaller..equal-1
    //unclassified : equal..larger-1
    //large group  : large..A.size()-1
    int equal = 0, smaller = 0, larger = n; 
    while(equal < larger){
        if(A[equal] < pivot){
            swap(A[equal], A[smaller]);
            equal++; 
            smaller++;
        
        }else if(A[equal] == pivot){
            equal++;     
        }else{ //A[equal] > pivot
            swap(A[equal], A[larger-1]);
            larger -- ; 
        }
    }
    return A; 
}

int main(){
    vector<int> A = { 1, 2, 3, 4, 3, 2 ,1, -1, 5, 6, 7};
    print_vector(A); 
    A =    sort(2, A); 
    print_vector(A); 
    return 1; 
}
-=EndlessGamer=- — Today at 10:09 PM
// C++ program to sort an array  
#include<bits/stdc++.h>  
using namespace std;  

// Function to sort the input array, 
// the array is assumed  
// to have values in {0, 1, 2}  
void DNFS(int arr[], int arr_size)  
{  
    int low = 0;  
    int high = arr_size - 1;  
    int mid = 0;  
      
    // Iterate till all the elements 
    // are sorted  
    while (mid <= high)  
    {  
        switch (arr[mid])  
        {  
              
            // mid is 0  
        case 0:  
            swap(arr[low++], arr[mid++]);  
            break;  
              
            // mid is 1 .  
        case 1:  
            mid++;  
            break;  
              
            // mid is 2  
        case 2:  
            swap(arr[mid], arr[high--]);  
            break;  
        }  
    }  
}  
  
  
  
// Function to print array arr[]  
void printArray(int arr[], int arr_size)  
{  
    // Iterate and print every element  
    for (int i = 0; i < arr_size; i++)  
        cout << arr[i] << " ";  
  
}  
  
// Driver Code  
int main()  
{  
    int arr[] = {0,0,1,2,0,1,2};  
    int n = sizeof(arr)/sizeof(arr[0]);  

    cout << "Array before running the algorithm: ";  
      
    printArray(arr, n);   
    
    DNFS(arr, n);  
  
    cout << "\nArray after DNFS algorithm: ";  
      
    printArray(arr, n);  
  
    return 0;  
}  
convert the array to vector
on your vscode
and send off PR
﻿
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& array, int startL, int endL, int startR, int endR) {
  vector<int> left(array.begin() + startL, array.begin() + endL + 1);
  vector<int> right(array.begin() + startR, array.begin() + endR + 1);
  int mergeArrayStart = startL, leftIndex = 0, rightIndex = 0;

  while (leftIndex < left.size() && rightIndex < right.size()) {
    if (left[leftIndex] >= right[rightIndex]) {
      array[mergeArrayStart++] = right[rightIndex++];
    } else if (left[leftIndex] < right[rightIndex])
      array[mergeArrayStart++] = left[leftIndex++];
  }

  while (leftIndex < left.size()) array[mergeArrayStart++] = left[leftIndex++];
  while (rightIndex < right.size())
    array[mergeArrayStart++] = right[rightIndex++];
}
void mergeSort(vector<int>& array, int start, int end) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;

  mergeSort(array, start, mid);
  mergeSort(array, mid + 1, end);
  merge(array, start, mid, mid + 1, end);
}

int main() {
  vector<int> a = {0, 0};
  mergeSort(a, 0, a.size() - 1);
  for (int i : a) cout << i << " ";
  return 0;
}
mergeSort.cpp
2 KB
