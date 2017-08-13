/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2,0);
        int sum =0;
        for(int num:nums){
            sum ^= num;
        }
        sum &= -sum;
        for(int num:nums){
            if(num & sum)
                ret[0] ^= num;
            else
                ret[1] ^=num;
        }
        return ret; 
    }
};