/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        int ptr = 2;
        int pre = nums[1];
        int prepre = nums[0];
        for(int i=2;i<nums.size();i++){
            if(nums[i] != pre || nums[i] != prepre){
                prepre = pre;
                pre = nums[i];
                nums[ptr] = nums[i];
                ptr++;
            }else{
                prepre = pre;
                pre = nums[i];
            }
        }
        return ptr;
    }
};