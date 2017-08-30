/*

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ret;
        if(nums.size()==0)
            return ret;
        int cur=0;
        int dp[nums.size()], pre[nums.size()];
        fill(dp, dp+nums.size(), 1);
        fill(pre, pre+nums.size(), -1);
        sort(nums.begin(), nums.end());
        int max[2];
        max[0] = 1;
        max[1] = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i] <dp[j] +1){
                        dp[i] = dp[j] +1;
                        pre[i] = j;
                        if(dp[i] > max[0]){
                            max[0] = dp[i];
                            max[1] = i;
                        }
                    }
                }
            }
        }
        cur = max[1];
        while(cur!=-1){
            ret.insert(ret.begin(), nums[cur]);
            cur = pre[cur];
        }
        return ret;
    }
};