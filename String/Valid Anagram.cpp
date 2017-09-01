/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(int i=0;i<s.size();i++)
            map[s[i]]++;
        for(int i=0;i<t.size();i++){
            map[t[i]]--;
            if(map[t[i]]<0)
                return false;
            if(map[t[i]]==0)
                map.erase(t[i]);
        }
        if(map.size()>0)
            return false;
        else
            return true;
    }
};