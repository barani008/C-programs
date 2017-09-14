/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i-1]* nums[i];
            //cout<<nums[i]<<" ";
        }
        //cout<<endl;
        for(int i=nums.size()-2;i>=0;i--){
            ret[i] = ret[i] * ret[i+1];
        }
        ret[0] = ret[1];        
        for(int i=1;i<nums.size()-1;i++){
            ret[i] = nums[i-1] * ret[i+1];
        }
        ret[nums.size()-1] = nums[nums.size()-2];
        return ret;
    }
};