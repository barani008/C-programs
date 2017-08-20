/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char, char> map;
        unordered_set<char> set;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                if(map[s[i]]!=t[i])
                    return false;
            }else if(set.find(t[i])!=set.end()){
                return false;
            }else{
                map[s[i]] = t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};