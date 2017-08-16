/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> set;
        permute(nums, set, 0);
        vector<vector<int>> ret(set.begin(), set.end());
        return ret;
    }
    
    void permute(vector<int> nums, set<vector<int>>& set, int ind){
        if(ind == nums.size()){
            set.insert(nums);
            return;
        }
        permute(nums, set, ind+1);
        for(int i=ind+1;i<nums.size();i++){
            int tmp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = tmp;
            permute(nums, set, ind+1);
        }
    }
};