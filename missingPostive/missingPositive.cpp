/*Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
// Time Complexity O(nlogn)
int firstMissingPositive(vector<int>& nums) {       
  int cvalue = 1;
  sort(nums.begin(), nums.end());
  for(unsigned int i = 0; i < nums.size(); i++) {
      if(nums[i] == cvalue) {
          cvalue++;
      } 
  }
  return cvalue;
}


// Shift -ves to left
int segregate (vector<int>& nums) {
  int j = 0;
  // Time Complexity O(n)
  for(int i = 0; i < (int)nums.size(); i++) {
    if(nums[i] < 0) {
      if(i != j) {

          // XOR swap
          nums[i] = nums[i] ^ nums[j];
          nums[j] = nums[i] ^ nums[j];
          nums[i] = nums[i] ^ nums[j];
      }
      j++;
    }
  }
  return j;
}

// Utility function to mark +ves and return first non marked
int findPositiveUtil(vector<int>& nums, int shift) {
  int i = 0;

  // Fixing -ves to avoid confusion w/ marked indices
  for(i = 0; i < shift; i++) {
      nums[i] = abs(nums[i]);
  }

  // Time Complexity O(n)
  for(i = shift; i < (int)nums.size(); i++) {
      if(nums[i] <= nums.size() && nums[i] > 0) {
          if((nums[i] - 1) > i) {
            // XOR Swap
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
            i--;
            continue;
          } else {
            nums[nums[i] - 1] = -1;
          }
      }
  }

  // Time Complexity O(n)
  for(i = 0; i < (int) nums.size(); i++) {
      if(nums[i] != -1) {
          return i+1;
      }
  }
  return i+1;
}

// More optimized implementation O(n) time
int findPositive(vector<int>& nums) {
  int shift = segregate(nums);
  return findPositiveUtil(nums, shift);
}

// Main Function
int main() {
  vector <int> arr = {-1, -3, 4, 2, 1};
  // More optimized implementation O(n) time - segregate -ves and mark +ves
  cout<<findPositive(arr);
  return 0;
}
