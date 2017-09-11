/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return false;
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > nums[hi]){
                if(nums[lo]<= target && nums[mid] > target)
                    hi = mid-1;
                else
                    lo = mid+1;
            }else if(nums[mid] < nums[hi]){
                if(nums[hi] >= target && nums[mid] < target)
                    lo = mid+1;
                else
                    hi = mid-1;
            }else
                hi--;
        }
        return false;
    }
};