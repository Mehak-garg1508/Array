// Segregate 0s and 1s

// Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s 
// onto the left side and 1s onto the right side of the array.

// Input: arr[] = [0, 0, 1, 1, 0]
// Output: [0, 0, 0, 1, 1]
// Explanation:  After segregation, all the 0's are on the left and 1's are on the right.
//  Modified array will be [0, 0, 0, 1, 1].

#include<iostream>
using namespace std;

void print(int arr[],int size, int index){
  if(index == size){
    return;
  }
  cout << arr[index] << " ";
  print(arr,size,index+1);
}

int main(){
  int arr[5] = {0,0,1,1,0};
  int n = 5;
  // Normal Approach using loop
  int count0 = 0, count1 = 0;
  for(int i = 0; i < n; i++){
  if(arr[i] == 0){
    count0++;
  }
  if(arr[i] == 1){
    count1++;
  }
  }
  for(int i = 0; i < count0; i++){
    arr[i] = 0;
  }
  for(int i = count0; i<n; i++){
    arr[i] = 1;
  }
  cout << "Output: " ;
  print(arr,n,0);
  cout << endl;
  
  // By using two pointer
  int start = 0;
  int end = n - 1;
  while(start <= end){
    if(arr[start]==0){
      start++;
    }
    else{
      if(end == 0){
        swap(arr[start],arr[end]);
        start++;
        end--;
      }
      else{
        end--;
      }
    }
  }
  cout << "Output: ";
  print(arr,n,0);
}