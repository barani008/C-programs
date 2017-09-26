/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int dp[nums.size()];
        int cnt[nums.size()];
        int max_val = 1;
        int max_count =1;
        fill(dp, dp+nums.size(), 1);
        fill(cnt, cnt+nums.size(), 1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }else if(dp[i] == dp[j]+1){
                        cnt[i] += cnt[j];
                    }
                }           
            }
            if(max_val < dp[i]){
                max_val = dp[i];
                max_count = cnt[i];
            }else if(max_val == dp[i]){
                max_count += cnt[i];
            }
        }
        return max_count;
    }
};