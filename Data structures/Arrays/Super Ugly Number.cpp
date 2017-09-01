/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(primes.size()==0)
            return n;
        int arr[primes.size()];
        fill(arr, arr+primes.size(), 0);
        vector<int> ret;
        ret.push_back(1);
        while(ret.size()!=n){
            int mini = INT_MAX;
            for(int i=0;i<primes.size();i++){
                mini = min(mini, primes[i]*ret[arr[i]]);
            }
            ret.push_back(mini);
            for(int i=0;i<primes.size();i++){
                if(mini == primes[i]*ret[arr[i]])
                    arr[i]++;
            }
        }
        return ret[n-1];
    }
};