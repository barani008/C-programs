/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int arr[target+1];
        fill(arr, arr+target+1, -1);
        arr[0] = 1;
        return findCombinations(nums, target, 0, arr);
    }
    
    int findCombinations(vector<int> nums, int target, int sum, int arr[]){
        if(arr[target-sum] != -1)
            return arr[target-sum];
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i] <= target)
                count += findCombinations(nums, target, sum+nums[i], arr);
        }
        arr[target-sum] = count;
        return count;
    }
};