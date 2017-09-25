/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string token1, token2;
        while(ss1.good() && ss2.good()){
            getline(ss1, token1, '.');
            getline(ss2, token2, '.');
            if(stoi(token1) > stoi(token2)){
                return 1;
            }else if(stoi(token1)<stoi(token2)){
                return -1;
            }
        }
        if(!ss1.good() && !ss2.good())
           return 0;
        else if(!ss1.good() && ss2.good()){
            while(getline(ss2, token2, '.') && stoi(token2)==0){}
            if(stoi(token2)!=0)
                return -1;
            else
                return 0;
        }
        else{
            while(getline(ss1, token1, '.') && stoi(token1)==0){}
            if(stoi(token1)!=0)
                return 1;
            else
                return 0;
        }
    }
};