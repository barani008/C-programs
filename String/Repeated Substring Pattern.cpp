/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0)
            return true;
        int i = 1, j = 0;
        vector<int> pat(s.size(), 0);
        while(i<s.size()){
            if(s[i] == s[j]){
                j++;
                pat[i] = j;
                i++;
            }else{
                if(j!=0){
                    j = pat[j-1];
                }else{
                    pat[i] = 0;
                    i++;
                }
            }
        }
        int sublen = s.size()-pat[s.size()-1];
        if(sublen == s.size())
            return false;
        string str = s.substr(0, sublen);       
        for(int i=sublen;i<s.size();i+=sublen){
            string str2 = s.substr(i, sublen);
            if(str.compare(str2)!=0)
                return false;
        }
        return true;
    }
};