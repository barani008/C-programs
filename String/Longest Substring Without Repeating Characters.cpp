/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int max1 = 0;
        int i=0, j = 0;
        for(i=0, j = 0;j<s.size();){
            //cout<<s[j]<<endl;
            if(set.find(s[j])==set.end()){
                set.insert(s[j]);
                j++;
            }else{
                max1 = max(max1, j-i);
                set.erase(s[i]);
                i++;
            }
        }
        max1 = max(max1, j-i);
        return max1;
    }
};