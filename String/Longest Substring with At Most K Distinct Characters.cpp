/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int start = 0;
        int max_sub = 0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            while(map.size()>k){
                map[s[start]]--;
                if(map[s[start]]==0)
                    map.erase(s[start]);
                start++;
            }
            max_sub = max(max_sub, i-start+1);
        }
        return max_sub;
    }
};