/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(ret, tmp, nums);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums){
        if(tmp.size()== nums.size()){
            ret.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(tmp.begin(), tmp.end(), nums[i])!=tmp.end())
                continue;
            tmp.push_back(nums[i]);
            dfs(ret, tmp, nums);
            tmp.erase(tmp.end()-1);
        }
    }
};