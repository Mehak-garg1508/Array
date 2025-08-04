// You are given an array with unique elements of stalls[], 
// which denote the positions of stalls. You are also given an integer k 
// which denotes the number of aggressive cows. The task is to assign stalls to 
// k cows such that the minimum distance between any two of them is the maximum possible.

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3

#include <iostream>
using namespace std;

int main(){
  int stalls[5] = {1,2,4,8,9};
  int k = 3;

  int start = 0;
  int n = 5;
  int end = stalls[n-1] - stalls[0];
  int ans = 0;
  while(start <= end){
    int mid = start + (end - start)/2;
    int count = 1;
    int pos = stalls[0];
    for(int i = 0; i < n; i++){
      if(pos + mid <= stalls[i]){
        pos = stalls[i];
        count++;
      }
    }
    if(count < k){
      end = mid - 1;
    }
    else{
      ans = mid;
      start = mid + 1;
    }
  }
  cout << "Minimum distance between any two cows: " << ans;
}