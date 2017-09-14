/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        bool arr[n];
        fill(arr, arr+n, true);
        int count = 0;
        for(int i = 2;i<n;i++){
            if(arr[i])
                count++;
            for(int j=2;j*i<n;j++){
                arr[i*j] = false;
            }
        }
        return count;
    }
};