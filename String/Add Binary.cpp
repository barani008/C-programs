
/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int a1 = a.size();
        int b1 = b.size();
        string ret = "";
        for(int i=1;i<=max(a1, b1);i++){
            int sum = carry;
            if(a1>=i)
                sum += a[a1-i]-'0';
            if(b1>=i)
                sum += b[b1-i]-'0';
            carry = sum/2;
            ret = to_string(sum%2) + ret;
        }
        //cout<<ret;
        if(carry>0){
            ret = to_string(carry) + ret;
        }
        return ret;
    }
};