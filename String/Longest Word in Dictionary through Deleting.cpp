/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

struct less_than{
    bool operator()(const string& s1,const string& s2){
        if(s1.size()>s2.size())
            return true;
        else if(s1.size()<s2.size())
            return false;
        else{
            if(s2.compare(s1)<0)
                return 0;
            else
                return 1;
        }
    }  
};
class Solution {
public:
    bool isSubSeq(string s, string t){
        int ptr = 0;
        for(int i=0;i<s.size() && ptr<t.size();i++){
            if(s[i]==t[ptr])
                ptr++;
        }
        if(ptr==t.size())
            return true;
        else
            return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), less_than());
        for(string str:d){
            //cout<<str<<endl;
            if(str.size()<=s.size() && isSubSeq(s, str)){
                return str;
            }
        }
        return "";
    }
};