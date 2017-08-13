/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(unsigned int mask = 1, i=0;i<32;i++, mask<<=1){
            int count =0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] & mask){
                    count++;
                    count %=3;
                }
            }
            if(count !=0){
                ret |= mask;
            }
        }
        return ret;
    }
};