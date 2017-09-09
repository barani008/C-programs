/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/
class Solution {
public:
    int myAtoi(string str) {
        int i=0, sign = 1;
        long value = 0;
        if(str.size()==0)
            return 0;
        while(str[i]==' ')
            i++;
        if(str[i]=='-'){
            sign = -1;
            i++;
        }
        else if(str[i]=='+'){
            i++;
        }
        while(str[i]<='9' && str[i]>='0'){
            value *= 10;
            value += str[i]-'0';
            if(value*sign > INT_MAX)
                return INT_MAX;
            if(value*sign < INT_MIN)
                return INT_MIN;
            i++;
        }
        //cout<<value;
        return (int) (value*sign);
    }
};