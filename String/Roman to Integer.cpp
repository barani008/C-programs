/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I']= 1;
        map['V']= 5;
        map['X']= 10;
        map['L']= 50;
        map['C']= 100;
        map['D']= 500;
        map['M']= 1000;
        if(s.size()==0)
            return 0;
        int cur = map[s[0]];
        int sum = 0;
        for(int i=1;i<s.size();i++){
            int pre = cur;
            cur = map[s[i]];
            if(cur<=pre){
                sum += pre;
            }else{
                sum -= pre;
            }
        }
        sum += cur;
        return sum;
    }
};