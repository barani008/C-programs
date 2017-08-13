/*

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
class Solution {
public:
    int titleToNumber(string s) {
        unordered_map<char, int> map;
        int count = 0;
        for(int i=65;i<=90;i++){
            char ch = (char)i;            
            map[ch] = i-64;
            //cout<<map[ch]<<endl;
        }
        for(int i=s.size()-1;i>=0;i--){
            count += map[s[i]] * pow(26,(s.size()-1-i));
        }
        return count;
    }
};