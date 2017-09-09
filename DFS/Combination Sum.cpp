/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        findCombinations(ret, tmp, candidates, 0, target, 0);
        return ret;
    }
    
    void findCombinations(vector<vector<int>>& ret, vector<int> tmp, vector<int>& candidates,
                          int index, int target, int val){        
        if(val == target){
            //cout<<val<<endl;
            ret.push_back(tmp);
            return;
        }
        if(candidates.size() == index)
            return;
        for(int i=index;i<candidates.size();i++){
            vector<int> local(tmp.begin(), tmp.end());
            if(val+candidates[i] <=target){
                local.push_back(candidates[i]);
                findCombinations(ret, local, candidates, i, target, val+candidates[i]);
            }
        }
    }
};