/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)
             return 0;
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        fill(&dp[0][0], &dp[row-1][col-1], 0);
        dp[0][0] = grid[0][0];
        for(int i=1;i<row;i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int j=1;j<col;j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[row-1][col-1];
    }
};