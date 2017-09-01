/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        unordered_set<char> chars[3];
        string str[3]= {"QWERTYUIOP", "ASDFGHJKL","ZXCVBNM"};
        for(int i=0;i<=2;i++){
            for(int j=0;j<str[i].size();j++){
                chars[i].insert(str[i][j]);
            }
        }
        for(int i=0;i<words.size();i++){
            bool found = false;
            int row = 0;
            if(words[i].size()==0)
                continue;
            else{
                char ch= words[i][0];
                if((int)words[i][0] >= 97 && (int)words[i][0]<=122)
                    ch = (char)((int)words[i][0] - 32);
                while(chars[row].find(ch)==chars[row].end())
                    row++;
                //cout<<row;
            }            
            for(int j=0;j<words[i].size();j++){
                char ch = words[i][j];
                if((int)words[i][j] >= 97 && (int)words[i][j]<=122)
                    ch = (char)((int)words[i][j] - 32);
                //cout<<words[i][j];
                if(chars[row].find(ch)==chars[row].end())
                    found = true;
            }
            //cout<<endl;
            if(!found)
                ret.push_back(words[i]);
        }
        return ret;
    }
};