/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> map;
        int max_sub =0;
        int start =0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            while(map.size()>2){
                map[s[start]]--;
                if(map[s[start]]==0){
                    map.erase(s[start]);
                }
                start++;
            }
            max_sub = max(max_sub, i-start+1);
        }
        return max_sub;
    }
};