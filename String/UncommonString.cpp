/*
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].

*/
struct order_size{
    bool operator()(const string& s1, const string& s2){
        return s1.size()>s2.size();
    }
};
class Solution {
public:
    bool isSubSeq(string s, string t){
        int ptr2 = 0;
        for(int i=0;i<s.size()&& ptr2<t.size();i++){
            if(s[i]==t[ptr2])
                ptr2++;
        }
        if(ptr2==t.size())
            return true;
        else
            return false;
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), order_size());
        vector<bool> unique(strs.size(), true);
        for(int i=0;i<strs.size();i++){
            string first = strs[i];
            int j = 0;
            while(j<strs.size()){
                if(j!=i && isSubSeq(strs[j],strs[i])){
                    unique[i] = false;
                    break;                    
                }
                j++;
            }
            if(unique[i])
                return strs[i].size();
        }
        return -1;
    }
};