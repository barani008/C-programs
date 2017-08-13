
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size()-1;
        vector<int> vect;
        while(lo<hi){
            if(nums[lo]+nums[hi]==target){
                vect.push_back(lo);
                vect.push_back(hi);
                return vect;
            }else if(nums[lo]+nums[hi]>target)
                hi--;
            else
                lo++;
        }
        vect.push_back(lo);
                vect.push_back(hi);
                return vect;
    }
};