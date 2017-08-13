class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        unordered_map<int, int> map;
        map[0] = 0;
        int presum =0, min1 =nums.size()+1;
        for(int i=1;i<=nums.size();i++){
            presum += nums[i-1];
            //cout<<presum<<endl;
            auto got = map.find(presum-s);
            if(got!=map.end()){
                min1 = min(min1, i-map[presum-s]);
            }
            map[presum] = i;
        }
        if(min1==nums.size()+1)
            return 0;
        return min1;
    }
};