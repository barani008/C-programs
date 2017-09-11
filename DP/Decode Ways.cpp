/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0 ||  s[0]=='0')
            return 0;
        int dp[s.size()+1];
        fill(dp, dp+ s.size()+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0')? 0:1;
        for(int i=2;i<=s.size();i++){
            string s1 = s.substr(i-1, 1);
            string s2 = s.substr(i-2, 2);
            if(stoi(s1)>=1 && stoi(s1)<= 9)
                dp[i] += dp[i-1];
            if(stoi(s2)>=10 && stoi(s2)<=26)
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};