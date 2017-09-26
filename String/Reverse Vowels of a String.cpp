/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set{'a','e','i','o','u', 'A', 'E', 'I', 'O','U'};
        int ptr = 0, ptr1 = s.size()-1;
        while(ptr<ptr1){
            if(set.find(s[ptr])!=set.end()){
                while(ptr1>ptr && set.find(s[ptr1])==set.end()){
                    ptr1--;
                }
                if(ptr1>ptr){
                    char tmp = s[ptr];
                    s[ptr] = s[ptr1];
                    s[ptr1] = tmp;
                }
                ptr1--;
            }
            ptr++;
        }
        return s;
    }
};