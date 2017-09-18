/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int dp[t.size()+1][s.size()+1];
        fill(&dp[0][0], &dp[t.size()][s.size()], 0);
        for(int i=0;i<=s.size();i++)
            dp[0][i] = 1;
        for(int i=1;i<=t.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[j-1] == t[i-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};