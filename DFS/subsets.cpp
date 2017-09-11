/*Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp;
        ret.push_back(tmp);
        if(nums.size()==0)
            return ret;
        subset(ret, nums, tmp, 0);
        return ret;
    }
    
    void subset(vector<vector<int>>& ret, vector<int>& nums, vector<int> tmp, int index){        
        for(int i=index;i<nums.size();i++){
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            subset(ret, nums, tmp, i+1);
            tmp.erase(tmp.end()-1);
        }
    }
};