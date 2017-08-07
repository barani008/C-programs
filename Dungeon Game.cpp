class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        vector<int> path;
        int ret = 0;
        if(row == 0)
            return 0;
        int col = dungeon[0].size();
        int dp[row+1][col+1];
        fill(dp[0], dp[row]+col, INT_MAX);
        dp[row][col-1] = 1;
        dp[row-1][col] = 1;
        for(int i = row-1; i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int req = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = req <=0? 1:req;
            }
        }
        return dp[0][0];
    }
};