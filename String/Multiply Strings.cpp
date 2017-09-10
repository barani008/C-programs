/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size()==0 || num2.size()==0)
            return "";
        if(num1=="0" || num2=="0")
            return "0";
        int size1 = num1.size();
        int size2 = num2.size();        
        string ret="";
        for(int j=1;j<=size1;j++){
            string cur = "";
            int carry = 0, i = 0;
            for(i=1;i<=size2;i++){
                int prod = (num1[size1-j]-'0')*(num2[size2-i]-'0') + carry;
                carry = prod/10;
                cur = to_string(prod%10)+cur;
            }
            if(carry!=0){
                cur = to_string(carry)+cur;
            }
            for(int k=1;k<j;k++){
                cur += "0";
            }
            //cout<<cur<<endl;
            //cout<<ret<<endl;
            ret = add(ret, cur); 
            //cout<<endl;
        }
        return ret;
    }
    
    string add(string num1, string num2){
        int carry = 0, i=1;
        int size1 = num1.size();
        int size2 = num2.size();
        string ret = "";
        for(i=1;i<=min(num1.size(), num2.size());i++){
            int sum = (num1[size1-i]-'0')+(num2[size2-i]-'0') + carry;
            carry = sum/10;
            ret = to_string(sum%10)+ret;
        }
        //cout<<i<<" "<<carry<<" "<<ret<<endl;
        if(i<=size2){
            while(carry!=0 && i<=size2){
                int sum = (num2[size2-i]-'0') + carry;
                carry = sum/10;
                ret = to_string(sum%10)+ret;
                i++;
            }
            if(i<=size2){
                ret = num2.substr(0, size2-i+1)+ret;
            }    
        }
        else if(i<=size1){
            while(carry!=0 && i<=size1){
                int sum = (num1[size1-i]-'0') + carry;
                carry = sum/10;
                ret = to_string(sum%10)+ret;
                i++;
            }
            if(i<=size1){
                ret = num1.substr(0, size1-i+1)+ret;
            }    
        }
        if(carry!=0){
            ret = to_string(carry) + ret;
        }
        //cout<<ret<<endl;
        return ret;
    }
};