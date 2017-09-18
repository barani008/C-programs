/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i=0;i<=n;i++)
            dp[i] = i;
        for(int i=2;i*i<=n;i++){
            int sq = i*i;
            int j = sq;
            while(j <= n){
                dp[j] = min(dp[j] , dp[j-sq] + 1);
                j++;
            }
        }
        return dp[n];
    }
};