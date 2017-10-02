/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        int count[2];
        count[0] = 0;
        count[1] = 0;
        int max_len =0;
        if(nums.size()<2)
            return 0;
        hash_map[0] = -1;
        for(int i=0;i< nums.size();i++){
            count[nums[i]]++;
            if(hash_map.find(count[0]-count[1])!=hash_map.end()){
                max_len = max(max_len, i-hash_map[count[0]-count[1]]);
            }else{
                hash_map[count[0]-count[1]] = i;
            }
        }
        return max_len;
    }
};