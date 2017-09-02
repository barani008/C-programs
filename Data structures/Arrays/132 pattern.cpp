/*

Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        bool max_set = false;
        int max1 = INT_MIN; 
        for(int i=nums.size()-1;i>=0;i--){
            if(stk.empty()){
                stk.push(nums[i]);
            }else{
                if(stk.top()<nums[i]){
                    while(!stk.empty() && stk.top()<nums[i]){
                        max1 = max(stk.top(), max1);
                        max_set = true;
                        stk.pop();
                    }
                    stk.push(nums[i]);
                }else{
                    if(max_set && nums[i]<max1)
                        return true;
                    stk.push(nums[i]);
                }
            }
        }
        return false;
    }
};