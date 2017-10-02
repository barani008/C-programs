/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1));
    }
    
    int rob(vector<int>& nums, int lo, int hi) {
        int len = hi-lo;
        if(lo > hi)
            return 0;
        int exclude = 0, include = nums[lo];
        for(int i=lo+1;i<=hi;i++){
            int ex = include;
            int in = max(exclude+ nums[i], include);
            exclude = ex;
            include = in;
        }
        return max(include, exclude);
    }
};