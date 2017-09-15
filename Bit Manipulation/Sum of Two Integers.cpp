/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/
class Solution {
public:
    int getSum(int a, int b) {
        bool carry = 0;
        int ret = 0;
        for(int i=0;i<32;i++){
            if((a & (1<<i)) && (b & (1<<i)) && carry){
                ret |= (1<<i);
                carry = 1;
            }else if(((a & (1<<i)) && (b & (1<<i)))|| 
                     ((a & (1<<i)) && carry) || (carry && (b & (1<<i)))){
                ret |= (0<<i);
                carry = 1;
            }else if((a & (1<<i)) || (b & (1<<i)) || carry){
                ret |= (1<<i);
                carry = 0;
            }else{
                ret |= (0<<i);
                carry = 0;
            }
        }
        return ret;
    }
};