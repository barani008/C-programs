/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
        int ind = 1;
        if(num<1)
            return false;
        while(num>0){
            if((num & 1 )==1 && (ind%2==0 || num>1)){
                return false;
            }else{
                num = num>>1;
            }
            ind++;
        }
        return true;
    }
};