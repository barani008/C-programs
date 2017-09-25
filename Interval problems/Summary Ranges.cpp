/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
*/
class Solution {
public:
    void format(vector<string>& ret, int start, int end){
        if(start == end){
            string str = to_string(start);
            ret.push_back(str);
            return;
        }
        string str = to_string(start);
        str += "->";
        str += to_string(end);
        ret.push_back(str);
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.size()==0)
            return ret;
        int start = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]-1 || nums[i-1]== nums[i])
                continue;
            else{
                format(ret, start, nums[i-1]);
                start = nums[i];
            }
        }
        if(start <= nums.back()){
            format(ret, start, nums.back());
        }
        return ret;
    }
};