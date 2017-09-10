/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2)
            return;
        int i = nums.size()-1;
        for(;i>=1;i--){
            if(nums[i]>nums[i-1])
                break;
        }
        if(i!=0){
            //cout<<i<<endl;
            int k = nums.size()-1;
            while(k>=i){
                if(nums[k] > nums[i-1])
                    break;
                k--;
            }
            swapVal(nums, k, i-1);
            reverse(nums.begin()+i, nums.end());
        }else{
            reverse(nums.begin(), nums.end());
        }       
    }
    
    void swapVal(vector<int>& nums, int k, int i){
        int tmp = nums[k];
        nums[k] = nums[i];
        nums[i] = tmp;
    }
};