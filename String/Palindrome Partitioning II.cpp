/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        if(s.size()<2)
            return 0;
        int minCuts[size+1];
        for(int i=0;i<=size;i++)
            minCuts[i] = i-1;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for(int j=1;j<size;j++){
            for(int i=j;i>=0;i--){
                if(s[j]==s[i] && ((j-i<=1)||dp[i+1][j-1])){
                    dp[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], minCuts[i]+1);
                }
            }
        }
        return minCuts[size];
    }
};