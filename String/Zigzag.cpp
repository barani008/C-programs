/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> matrix(numRows);
        int ptr = 0;
        bool asc = true;
        string ret;
        for(int i=0;i<s.size();i++){
            //cout<<ptr<<endl;
            if(asc){
                matrix[ptr].push_back(s[i]);
                ptr++;
            }else{
                matrix[ptr].push_back(s[i]);
                ptr--;
            }
            if(ptr >= numRows-1 && asc){
                asc = false;
                ptr = numRows-1;
            }else if(ptr <= 0 && !asc){
                asc = true;
                ptr = 0;
            }
        }
        for(vector<char> vect: matrix){
            for(char ch:vect){
                ret+= ch;
            }
        }
        return ret;
    }
};