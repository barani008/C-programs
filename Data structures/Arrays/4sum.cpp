/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size()<4)
            return ret;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;){
            for(int j=i+1;j<nums.size()-2;){
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    if(nums[i]+nums[j]+nums[k]+nums[l] == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[l]);
                        ret.push_back(tmp);
                        k++;
                        l--;
                        while(k<l && nums[k-1] == nums[k])
                            k++;
                        while(l>k && nums[l] == nums[l+1])
                            l--;
                    }else if(nums[i]+nums[j]+nums[k]+nums[l] < target){
                        k++;
                    }else{
                        l--;
                    }
                }
                j++;
                while(j<nums.size()-2 && nums[j]==nums[j-1])
                    j++;
            }
            i++;
            while(i<nums.size()-3 && nums[i]==nums[i-1])
                i++;
        }
        return ret;
    }
};