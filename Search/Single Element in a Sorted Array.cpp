/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int i:nums){
            res ^=i;
        }
        return res;
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(mid == 0 && nums[mid]!= nums[mid+1])
                return nums[mid];
            if(mid==nums.size()-1 && nums[mid]!=nums[mid-1])
                return nums[mid];
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid])
                return nums[mid];
            if(mid%2==1 && nums[mid-1] == nums[mid] || (mid%2==0 && nums[mid+1]==nums[mid]))
                lo = mid+1;
            else
                hi = mid;
        }
        return nums[lo];
    }
};