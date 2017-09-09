/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string strs[] = {"abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        if(digits.size()==0)
            return ret;
        dfs(strs, ret, "", digits, 0);
        return ret;
    }
    
    void dfs(string strs[], vector<string>& ret, string tmp, string digits, int i){
        if(i == digits.size()){
            ret.push_back(tmp);
            return;
        }
        if(digits[i]!='1' && digits[i]!='0'){
            dfs(strs, ret, tmp+strs[digits[i]-'2'][0], digits, i+1);
            dfs(strs, ret, tmp+strs[digits[i]-'2'][1], digits, i+1);
            dfs(strs, ret, tmp+strs[digits[i]-'2'][2], digits, i+1);
            if(digits[i]=='7'||digits[i]=='9')
                dfs(strs, ret, tmp+strs[digits[i]-'2'][3], digits, i+1);
        }
    }
};