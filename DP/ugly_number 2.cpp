/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        vector<int> vect(n);
        vect[0] = 1;
        int ptr2 = 0, ptr3=0, ptr5=0;
        for(int i=1;i<n;i++){
            vect[i]= min(vect[ptr2]*2, min(vect[ptr3]*3, vect[ptr5]*5));
            if(vect[i]==vect[ptr2]*2)
                ptr2++;
            if(vect[i]==vect[ptr3]*3)
                ptr3++;
            if(vect[i]==vect[ptr5]*5)
                ptr5++;
        }
        return vect[n-1];
    }
};