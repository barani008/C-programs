/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for(int i=31;i>=0;i--){
            mask = mask | (1<<i);
            unordered_set<int> set;
            for(int num:nums){
                set.insert(num & mask);
            }
            
            int tmp = max | (1<<i);
            for(int val:set){
                if(set.find(tmp^val)!=set.end()){
                    max = tmp;
                }
            }
        }
        return max;
    }
};