/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

public class Solution {
// you need to treat n as an unsigned value
public int hammingWeight(int n) {
    int result = 0;
    while(n!=0){
        n = n & (n-1);
        result++;
    }
    return result;
}

n&(n-1) the least significant set bit will be removed.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for(int i=0;i<nums.size();i++){
            val ^= nums[i];
        }
        return val;
    }
};
