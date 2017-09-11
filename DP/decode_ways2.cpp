/*
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        if(n==1)
            return ways(s[0]);
        long dp[2];
        dp[0] = ways(s[0]);
        dp[1] = dp[0]*ways(s[1]) + ways(s[0] , s[1]);
        for(int i=2;i<n;i++){
            long tmp = ((dp[0]*ways(s[i-1], s[i]))+(dp[1]*ways(s[i])))%1000000007;
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return (int)dp[1];
    }
    
    int ways(char ch){
        if(ch == '*')
            return 9;
        else if(ch == '0')
            return 0;
        else
            return 1;
    }
    
    int ways(char c1, char c2){
        if(c1 != '*' && c2 !='*'){
            string s;
            s.push_back(c1);
            s.push_back(c2);
            if(stoi(s) >=10 && stoi(s) <=26)
                return 1;
            else
                return 0;
        }else if(c1 == '*' && c2 == '*'){
            return 15;
        }else{
            if(c1=='*'){
                if(c2 >= '0' && c2<= '6'){
                    return 2;
                }else{
                    return 1;
                }
            }else{
                if(c1 == '1'){
                    return 9;
                }else if(c1 == '2'){
                    return 6;
                }else{
                    return 0;
                }
            }
        }
    }
};