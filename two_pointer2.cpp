// Two Sum II - Input Array Is Sorted

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
//  find two numbers such that they add up to a specific target number. Let these two numbers
//  be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer 
// array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. 
// You may not use the same element twice.

// Your solution must use only constant extra space.

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. 
// We return [1, 2].

#include<iostream>
#include <vector>
using namespace std;

void print(vector<int> &ans, int index){
  if(index == ans.size()){
    return;
  }
  cout << ans[index] << " ";
  print(ans, index+1);
}

int main(){
  int numbers[4] = {2,7,11,15};
  int n = 4;
  int target = 9;
  
  vector<int>ans;
  // first approach brute force approach:- Using Loops
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
    if(numbers[i] + numbers[j] == target){
    ans.push_back(i+1);
    ans.push_back(j+1);
    break;
    }
    }
  }
  cout << "Output: ";
print(ans,0);
cout << endl;

// 2: binary approach
  vector<int>ans1;
for(int i = 0; i < n-1; i++){
int x = target - numbers[i];
int start = i + 1;
int end = n - 1;
while(start <= end){
  int mid = start + (end - start)/2;
  if(numbers[mid] == x){
    ans1.push_back(i + 1);
    ans1.push_back(mid+ 1);
    break;
  }
  else if(numbers[mid] > x){
    end = mid - 1;
  }
  else{
    start = mid + 1;
  }
}
}
cout << "Output: ";
print(ans1,0);
cout << endl;

// 3: Two pointer Approach
int start = 0;
int end = n  - 1;
vector<int>ans3;
while(start<=end){
  if(numbers[start] + numbers[end] == target){
    ans3.push_back(start+1);
    ans3.push_back(end + 1);
    break;
  }
  else if(numbers[start] + numbers[end]  < target){
    start++;
  }
  else{
    end--;
  }
}
cout << "Output: ";
print(ans3,0);
}