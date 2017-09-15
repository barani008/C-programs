/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(haystack.size()==0)
            return -1;
        vector<int> pattern(needle.size(), 0);
        int i = 1, j = 0;
        while(i<needle.size()){
            if(needle[i]==needle[j]){
                j++;
                pattern[i] = j;
                i++;
            }else{
                if(j!=0){
                    j = pattern[j-1];
                }else{
                    pattern[i] = 0;
                    i++;
                }
            }
        }
        for(i=0, j=0;i<haystack.size();i++){
            cout<<j<<" "<<needle[j]<<" " <<haystack[i]<< endl;
            if(needle[j]==haystack[i]){
                j++;       
                if(j==needle.size())
                    return i-(needle.size()-1);
            }else{                        
                if(j!=0){ 
                    j = pattern[j-1];
                    i--;
                }
            }            
        }
        return -1;
    }
};