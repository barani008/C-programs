/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        int max1f = 0, max2f =0;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max1){
                max1f++;
            }else if(nums[i] == max2){
                max2f++;
            }else if(max1f ==0){
                max1 = nums[i];
                max1f = 1;
            }else if(max2f == 0){
                max2 = nums[i];
                max2f = 1;
            }else{
                max1f--;
                max2f--;
            }
        }
        max1f = 0;
        max2f =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == max1)
                max1f++;
            if(nums[i]== max2)
                max2f++;
        }
        if(max1f > (nums.size()/3))
            ret.push_back(max1);
        if(max1!=max2 && max2f > (nums.size()/3))
            ret.push_back(max2);
        return ret;
    }
};