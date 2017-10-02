/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class Solution {
public:
    string decodeString(string s) {
        int freq = 0;
        string cur = "";
        stack<int> stk;
        stack<string> rep;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i] <='9'){
                freq *= 10;
                freq += s[i]-'0';
            }else if(s[i]=='['){
                stk.push(freq);
                freq = 0;
                rep.push(cur);
                cur = "";
            }else if(s[i]==']'){
                int stkTop = stk.top();
                stk.pop();
                string curTop = rep.top();
                rep.pop();
                while(stkTop--){
                    curTop += cur;
                }
                cur = curTop;
            }else{
                cur += s[i];
            }
        }
        return cur;
    }
};