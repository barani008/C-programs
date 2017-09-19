/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size()+1][p.size()+1];
        fill(&dp[0][0], &dp[s.size()][0]+p.size()+1, false);
        dp[0][0] = true;
        for(int i=1;i<=p.size();i++)
        {
            if(i>1 && p[i-1]=='*' && dp[0][i-2])
                dp[0][i] = true;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(p[j-1]!='*'){
                    if(s[i-1] == p[j-1] || p[j-1] == '.')
                        dp[i][j] = dp[i-1][j-1];
                }else{
                    if(j>1 && dp[i][j-2] || (j>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]))
                        dp[i][j] = true;
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[s.size()][p.size()];
    }
};