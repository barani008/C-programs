/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
        for(unsigned int i=0, mask=1; i<32;i++,mask<<=1){
            int count =0;
            for(int j=0;j<nums.size();j++){                
                if(nums[j]&mask)
                    count++;
                if(count>(nums.size()/2)){
                    major |= mask;
                    break;
                }
            }
        }
        return major;
    }
};