/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int lo =0, hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums[hi]){
                if(target < nums[mid] && target>=nums[lo])
                    hi = mid-1;
                else
                    lo = mid+1;
            }else{
                if(target > nums[mid] && target<=nums[hi])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        
        return -1;
    }
};