/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ret;
        vector<int> tmp;
        dfs(candidates, tmp, ret, 0, target, 0);
        vector<vector<int>> res(ret.begin(), ret.end());
        return res;
    }
    
    void dfs(vector<int>& candidates, vector<int> tmp, set<vector<int>>& ret, int val, int target, int index){
        if(val==target){
            ret.insert(tmp);
            return;
        }            
        for(int i=index;i<candidates.size();i++){            
            if(val+candidates[i]<=target){
                vector<int> res(tmp.begin(), tmp.end());
                res.push_back(candidates[i]);
                dfs(candidates, res, ret, val+candidates[i], target, i+1);
            }
        }
    }
};