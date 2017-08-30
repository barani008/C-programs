/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd"
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string str;
        string ret(s);
        string rev(s);
        reverse(rev.begin(), rev.end());
        str = s+"#"+rev;
        vector<int> pattern(str.size(), 0);      
        int i = 1, j = 0;
        while(i<str.size()){
            if(str[i]==str[j]){
                j++;
                pattern[i] = j;
                i++;
            }else{
                if(j!=0){
                    j = pattern[j-1];
                }else{
                    pattern[i] = 0;
                    i++;
                }
            }
        }
        int end = pattern[str.size()-1];        
        for(int c= end;c<s.size();c++){
            ret = s[c] + ret ;
        }
        return ret;
    }
};