/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/
class Solution {
public:
    string customHash(int* freq){
        string ret;
        for(int i=0;i<26;i++){
            ret+=to_string(freq[i]);
            ret+=",";
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ret;
        int freq[26];        
        for(int i=0;i<strs.size();i++){
            fill(freq, freq+26, 0);
            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]-'a']++;
            }
            string hsh = customHash(freq);
            map[hsh].push_back(strs[i]);
        }
        for(auto it= map.begin();it!=map.end();it++){
            ret.push_back(it->second);
        }
        return ret;
    }
};