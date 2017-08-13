/*

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int max1 = 0;
        for(int i=0;i<heights.size();i++){
            if(stk.empty()){
                stk.push(i);
            }else{
                if(heights[stk.top()]<=heights[i]){
                    stk.push(i);
                }else{
                    while(!stk.empty() && heights[stk.top()]>=heights[i]){
                        int top = stk.top();
                        stk.pop();
                        if(stk.empty())
                            max1 = max(max1, heights[top]*i);
                        else{
                            max1 = max(max1, heights[top]*(i-1-stk.top()));
                        }                        
                        //cout<<max1<<" "<<top<<" "<<i<<endl;
                    }
                    stk.push(i);
                }
            }           
        }
        if(!stk.empty()){
            int top = stk.top();
            while(!stk.empty()){
                top = stk.top();
                        stk.pop();
                        if(stk.empty())
                            max1 = max(max1, (int)(heights[top]*heights.size()));
                        else
                            max1 = max(max1, (int)(heights[top]*(heights.size()-1-stk.top())));
                //cout<<max1<<" "<<top<<" "<<endl;        
            }
        }
        return max1;
    }
};