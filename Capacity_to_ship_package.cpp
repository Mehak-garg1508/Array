// Capacity to ship package with d days

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15

#include<iostream>
using namespace std;

int main(){
  int weights[10] = {1,2,3,4,5,6,7,8,9,10};
  int days = 5;

  int start = 0;
  int end = 0;
  int ans = 0;
  int n = 10;
  for(int i = 0; i < n; i++){
    start = max(start, weights[i]);
    end = end+weights[i];
  }
  while(start <= end){
    int mid = start + (end - start)/2;
    int d = 1;
    int w = 0;
    for(int i = 0; i < n; i++){
      w +=weights[i];
      if(w>mid){
        w  = weights[i];
        d++;
      }
    }
    if(d<= days){
      ans = mid;
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  cout << "Capacity to ship package is: " << ans;
}