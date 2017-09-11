/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {        
        vector<int> tmp;
        vector<vector<int>> ret;
        set<vector<int>> set;
        if(n==0 || k == 0 || n<k)
            return ret;
        vector<int> nums(n, 0);
        for(int i=1;i<=n;i++){
            nums[i-1] = i;
        }
        dfs(set, tmp, nums, k, 0);
        ret = vector<vector<int>>(set.begin(), set.end());
        return ret;
    }
    
    void dfs(set<vector<int>>& ret, vector<int> tmp, vector<int> nums, int k, int index){
        if(tmp.size() == k){
            ret.insert(tmp);
            return ;
        }
        if(nums.size() == index){
            return;
        }
        for(int i=index;i<nums.size();i++){
            vector<int> t(tmp.begin(), tmp.end());
            t.push_back(nums[i]);
            dfs(ret, t, nums, k, i+1);
        }
    }
};