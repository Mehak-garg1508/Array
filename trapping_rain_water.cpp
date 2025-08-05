// Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
// In this case, 6 units of rain water (blue section) are being trapped.
 
#include <iostream>
#include<vector>
using namespace std;

int main(){
  int heights[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int n = 12; //size
  // For time complexity O(n) 
  // and space complexity O(n)
  vector<int>leftmax(n);
  vector<int>rightmax(n);
  leftmax[0] = 0;
  for(int i = 1; i < n; i++){
  leftmax[i] = max(leftmax[i-1], heights[i-1]);
  }
  rightmax[n-1] = 0;
  for(int i = n-2; i >= 0; i--){
  rightmax[i] = max(rightmax[i+1], heights[i+1]);
  }
  int water = 0;
  for(int i = 0; i <n; i++){
    int minheight = min(rightmax[i],leftmax[i]);
    if(minheight > heights[i]){
       water += (minheight - heights[i]);
    }
  }
  cout << "Total water stored is: " << water << endl;

  // For Time complexity - O(n) and space complexity - O(1)
  int leftmaxi = 0;
  int rightmaxi = 0;
  int maxheight = 0;
  int index = -1;
  
  // Finding the maximum value
  for(int i = 0; i < n; i++){
    if(maxheight < heights[i]){
      maxheight = heights[i];
      index = i;
    }
  }
  int water_stored = 0;
  // Left side
  for(int i = 1; i < index; i++){
  if(leftmaxi > heights[i]){
    water_stored += leftmaxi - heights[i];
  }
else{
  leftmaxi = heights[i];
}
  }
  // right side
  for(int i = n - 1; i > index; i--){
    if(rightmaxi > heights[i]){
      water_stored += rightmaxi - heights[i];
    }
   else{
  rightmaxi = heights[i];
}
  }
  cout << "Total water stored is: " << water_stored << endl;
}