/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long, long> map;
        if(k < 1)
            return false;
        if(t<0)
            return false;
        for(int i = 0;i<nums.size();i++){
            long num = (long)(nums[i]) - INT_MIN;
            long bucket = num/((long)t+1);
            if(map.find(bucket)!= map.end())
                return true;
            if(map.find(bucket-1)!=map.end() && num-map[bucket-1] <= t)
                return true;
            if(map.find(bucket+1)!=map.end() && map[bucket+1] - num <= t)
                return true;
            if(map.size()>=k){
                map.erase(((long)nums[i-k]-INT_MIN)/(long)(t+1));
            }
            map[bucket] = num;
         }
        return false;
    }
};