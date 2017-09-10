/*Implement pow(x, n).*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(x==1)
            return 1;
        if(x==-1 && n%2==0)
            return 1;
        else if(x==-1 && n%2==1)
            return -1;
        if(n==INT_MIN) return 0;
        double ret = 1;
        if(n < 0){
            n = -n;
            x = 1/x;
        }            
            while(n>0){
                if(n%2==1){
                    ret *= x;
                }
                x *=x;
                n >>=1;
            }
        return ret;
    }
};