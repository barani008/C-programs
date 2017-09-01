/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0, maxRight = 0;
        int water = 0;
        int left = 0, right= height.size()-1;
        while(left < right){
            if(height[left]<=height[right]){
                if(maxLeft<= height[left])
                    maxLeft = height[left];
                else
                    water += maxLeft - height[left];
                left++;
            }else{
                if(maxRight<= height[right])
                    maxRight = height[right];
                else
                    water += maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};