/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i=1;i<=9;i++){
            buildvect(ret, i, n);
        }
        return ret;
    }
    
    void buildvect(vector<int>& ret, int val, int n){
            if(val<=n){
                ret.push_back(val);
            }else{
                return;
            }
            for(int i=0;i<=9;i++){
                buildvect(ret, (val*10)+i, n);
            }
    }
};