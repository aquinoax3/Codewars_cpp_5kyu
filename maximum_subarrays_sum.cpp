// The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

// For example:

// Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// Output: 6 (Sum of [4, -1, 2, 1])
// Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead. Your solution should be fast, it will be tested on very large arrays so slow solutions will time out.

// Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.



#include <vector>

int maxSequence(const std::vector<int>& arr){
  int left = 0;
  int currSum = 0;
  int maxSum = 0;
  
  for (int right = 0; right < arr.size(); right++) {
    currSum += arr[right];
    
    while (currSum < 0) {
      currSum -= arr[left];
      left++;
    }
    
    maxSum = std::max(maxSum, currSum);
  }
  
  return maxSum;
}
