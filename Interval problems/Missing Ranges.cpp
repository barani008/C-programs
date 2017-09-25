/*
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
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
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if(nums.size()==0){
            format(ret, lower, upper);
            return ret;
        }
        if(nums[0] > lower){
            format(ret, lower, nums[0]-1);
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1])
                continue;
            if(nums[i] != nums[i+1]-1){
                format(ret, nums[i]+1, nums[i+1]-1);
            }
        }
        if(nums.back() < upper){
            format(ret, nums.back()+1, upper);
        }
        return ret;
    }
};