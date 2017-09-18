/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ret;
        string res="";
        for(int i:nums){
            ret.push_back(to_string(i));
        }
        sort(ret.begin(), ret.end(), [](string s1, string s2){ return s1+s2 > s2+s1;});
        for(int i=0;i<ret.size();i++){
            res += ret[i];
        }
        while(res[0] == '0' && res.size()>1)
            res.erase(0, 1);
        return res;
    }
};