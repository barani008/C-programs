/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    void partition(vector<vector<string>>& ret, vector<string>& part, string s, bool** dp, int ind){
        if(ind == s.size()){
            ret.push_back(part);
            return; 
        }
        for(int i=ind;i<s.size();i++){
            if(dp[ind][i]){
                part.push_back(s.substr(ind, i-ind+1));
                partition(ret,part, s, dp, i+1);
                part.erase(part.end()-1);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        bool** dp = new bool*[s.size()];
        for(int i=0;i<s.size();i++)
            dp[i] = new bool[s.size()];
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                dp[i][j] = false;
            }
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j] && (i-j<=2 || dp[j+1][i-1]) )
                    dp[j][i] = true;
            }
        }
        vector<string> part;
        partition(ret, part, s, dp, 0);
        return ret;
    }
};