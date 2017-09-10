/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int maxSub = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] ==  '('){
                stk.push(i);
            }else{
                if(!stk.empty() && s[stk.top()]=='(')
                    stk.pop();
                else
                    stk.push(i);
            }
        }
        if(stk.empty())
            return s.size();
        int top = s.size();
        while(!stk.empty()){
            maxSub = max(maxSub, top-stk.top()-1);
            top = stk.top();
            stk.pop();
        }
        maxSub = max(maxSub, top);
        return maxSub;
    }
};