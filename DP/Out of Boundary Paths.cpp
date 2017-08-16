/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].
*/
class Solution {
public:
    int findPaths(int m, int n, int N, int I, int J) {
        int mod = 1000000007;
        if(m==0 || n==0 || N==0)
            return 0;
        int dp[m][n][N+1];
        fill(dp[0][0], dp[m-1][n-1]+N, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1){
                    dp[i][j][1] += 1;
                }
                if(i==0){
                    dp[i][j][1] += 1;
                }
                if(j==n-1){
                    dp[i][j][1] += 1;
                }
                if(j==0){
                    dp[i][j][1] += 1;
                }
            }
        }
        for(int i=2;i<=N;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    dp[j][k][i] += dp[j][k][1];
                    dp[j][k][i]%=mod;
                    if(j!=0){
                        dp[j][k][i] += dp[j-1][k][i-1];
                        dp[j][k][i]%=mod;
                    }if(k!=0){
                        dp[j][k][i] += dp[j][k-1][i-1];
                        dp[j][k][i]%=mod;
                    }if(j<m-1){
                        dp[j][k][i] += dp[j+1][k][i-1];                 
                        dp[j][k][i]%=mod;
                    }if(k<n-1){
                        dp[j][k][i] += dp[j][k+1][i-1];
                        dp[j][k][i]%=mod;
                    }
                    //cout<<dp[j][k][i]<<endl;
                }
            }
        }
        return dp[I][J][N];
    }
};