/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(ret, "", n, 0, 0);
        return ret;
    }
    
    void generate(vector<string>& ret, string s, int n, int open, int closed){
        if(open==n && closed == n){
            ret.push_back(s);
        }
        if(open<n){
            string str = s + "(";
            generate(ret, str, n, open+1, closed);
        }
        if(closed < open){
            string str = s + ")";
            closed++;
            generate(ret, str, n, open, closed);
        }
    }
};