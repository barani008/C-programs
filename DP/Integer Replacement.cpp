/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/
class Solution {
public:
    unordered_map<long, int> map;
    int integerReplacement(long n) {
        if(n==1)
            return 0;
        if(map.find(n)==map.end()){
            int res = 0;
            if(n%2==0)
                 res = integerReplacement(n/2)+1;
            else{
                 res = min(integerReplacement(n-1)+1, integerReplacement(n+1)+1);
            }
            map[n] = res;
            return res;
        }else{
            return map[n];
        }
        
    }
};