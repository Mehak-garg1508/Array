// Pair With Given Difference

// Given an one-dimensional unsorted array A containing N integers.

// You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

// Return Yes if any such pair exists else return No.

// Input 1:
//  A = [5, 10, 3, 2, 50, 80]
//  B = 78
// Input 2:
//  A = [-10, 20]
//  B = 30
// Output 1:  Yes
// Output 2:  Yes

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int arr[6] = {5, 10, 3, 2, 50, 80};
  // {2,3,5,10,50,80};
  int n = 6;
  int target = 78;
  int start = 0; 
  int end = start+1;
  int exist = 0;
  sort(arr,arr+n);
  while(end < n){
    if(arr[end] - arr[start] == target){
      // cout << "indexes are: ";
      // cout << start <<" " << end << endl;
      exist = 1;
      break;
    }
    else if(arr[end] - arr[start] > target){
      start++;
    }
    else{
      end++;
    }
  }
  if(exist){
  cout << "Yes, the pair exists";
  }
  else{
    cout << "No pair don't exist";
  }
}