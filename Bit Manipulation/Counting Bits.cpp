/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
class Solution {
public:
    vector<int> countBits(int num) {
        int ptr1 = 0, start = 2;
        vector<int> ret;
        ret.push_back(0);
        if(num==0)
            return ret;
        ret.push_back(1);
        if(num==1)
            return ret;
        while(ret.size()<=num){
            if(ptr1==start){
                start = ret.size();
                ptr1 = 0;
            }else{
                ret.push_back(ret[ptr1]+1);
                ptr1++;
            }
        }
        return ret;
    }
};