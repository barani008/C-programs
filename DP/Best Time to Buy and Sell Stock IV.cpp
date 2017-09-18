/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        long days = prices.size();
        if(days<2 || k==0)
            return 0;
        if(days/2 < k){
            int profit = 0;
            for(int i=1;i<days;i++){
                if(prices[i]>prices[i-1])
                    profit += prices[i] - prices[i-1];
            }
            return profit;
        }
        long dp[k+1][days];
        fill(&dp[0][0], &dp[k][days-1], 0);
        for(long i=1;i<=k;i++){
            long maxDiff = dp[i-1][0] - prices[0];
            for(long j=1;j<days;j++){                                 
                dp[i][j] = max(dp[i][j-1], maxDiff+prices[j]);
                maxDiff = max(maxDiff, dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][days-1];
    }
};