// Koko Eating Bananas
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas
//  from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Input: piles = [3,6,7,11], h = 8
// Output: 4

#include <iostream>
using namespace std;

int main(){
  int piles[4] = {3,6,7,11};
  int h = 8;
  int n = 4;
  int start = 0;
  int end = 0;

  for(int i = 0; i < n; i++){
    start+=piles[i];
    end  = max(end , piles[i]);
  }
  start = start / h;
int ans = 0;
  while(start < end){
    int mid = start + (end - start)/2;
    int total_time = 0;
    for(int i = 0; i< n; i++){
      total_time += piles[i]/mid;
      if(total_time % mid)
      total_time++;
    }
    if(total_time>h){
      start = mid + 1;
    }
    else{
      ans = mid;
      end = mid - 1;
    }
  }
  cout << "Minimum time taken to eat bananas: " << ans<< endl;
}