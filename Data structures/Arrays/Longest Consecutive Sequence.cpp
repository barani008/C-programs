/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int count = 0;
        for(int i:nums){
            set.insert(i);
        }
        for(int i:nums){
            int local = 0;
            if(set.find(i)!=set.end()){
                local++;
                int cur = i-1;
                while(set.find(cur)!=set.end()){
                    set.erase(cur);
                    cur--;
                    local++;
                }
                cur = i+1;
                while(set.find(cur)!=set.end()){
                    set.erase(cur);
                    cur++;
                    local++;
                }
                count = max(local, count);
            }
        }
        return count;
    }
};