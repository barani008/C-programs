/*

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 || dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int res = 0;
        int sign = 1;
        if(dividend<0 && divisor>0 || divisor<0 && dividend>0)
            sign = -1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        while(dvd>=dvs){
            long multiple = 1l;
            long tmp = dvs;
            while(dvd>=(tmp<<1)){                
                tmp = tmp<<1;
                multiple = multiple<<1;
            }
            dvd -= tmp;
            res += multiple;
        }
        return res*sign;
    }
};