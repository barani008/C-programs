/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int sum = n;
        while(sum != 1){            
            int squres = 0;
            while(sum>0){
                squres += (sum%10)*(sum%10);
                sum /= 10;
            }
            if(set.find(squres)!=set.end())
                return false;
            else
                set.insert(squres);
            sum = squres;
        }
        return true;
    }
};