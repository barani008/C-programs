/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        bool mat[s1.size()+1][s2.size()+1];
        mat[0][0] = true;
        for(int i=1;i<=s1.size();i++){
            if(s3[i-1]==s1[i-1] && mat[i-1][0])
                mat[i][0] = true;
            else
                mat[i][0] = false;
        }
        for(int i=1;i<=s2.size();i++){
            if(s3[i-1]==s2[i-1] && mat[0][i-1])
                mat[0][i] = true;
            else
                mat[0][i] = false;
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1] == s3[i+j-1] && mat[i-1][j]){
                    mat[i][j] = true;
                }else if(s2[j-1] == s3[i+j-1] && mat[i][j-1]){
                    mat[i][j] = true;
                }else{
                    mat[i][j] = false;
                }
            }
        }
        return mat[s1.size()][s2.size()];
    }
    
};