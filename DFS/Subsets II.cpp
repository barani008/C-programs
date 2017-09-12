/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> set;
        vector<int> tmp;
        ret.push_back(tmp);
        if(nums.size()==0)
            return ret;
        sort(nums.begin(), nums.end());
        subsets(set, tmp, nums, 0);
        ret.insert(ret.end(), set.begin(), set.end());
        return ret;
    }
    
    void subsets(set<vector<int>>& ret, vector<int> tmp, vector<int>& nums, int ind ){
        for(int i=ind;i<nums.size();i++){
            vector<int> t(tmp.begin(), tmp.end());
            t.push_back(nums[i]);
            ret.insert(t);
            subsets(ret, t, nums, i+1);
        }    
    }
    
};