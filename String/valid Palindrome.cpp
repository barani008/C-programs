/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<2)
            return true;
        for(int i=0;i<s.size();){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i]+32;
               // cout<<s[i];
                i++;
            }else if(i<s.size() && (s[i]<'0' || s[i]>'9') && (s[i]<'a' || s[i]>'z')){ 
                s.erase(s.begin()+i);
            }else{
               // cout<<s[i];
                i++;
            }            
        }
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i])
                return false;
        }
        return true;
    }
};