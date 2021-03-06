/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
public:
    vector<int> presum;
    NumArray(vector<int> nums) {
        if(nums.size()>0){
            presum.push_back(0);
            for(int i=1;i<=nums.size();i++){
                presum.push_back(nums[i-1]+presum[i-1]);
                //cout<<presum[i]<<endl;
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(i<presum.size() && j<presum.size()){
            return presum[j+1]-presum[i];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */