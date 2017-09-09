/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/    
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int minVal = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target){
                    return sum;
                }else if(sum > target){
                    k--;
                }else if(sum<target){
                    j++;
                }
                if(abs(sum-target)<minDiff){
                    minVal = sum;
                    minDiff = abs(sum-target);
                }
            }
        }
        return minVal;
    }
};