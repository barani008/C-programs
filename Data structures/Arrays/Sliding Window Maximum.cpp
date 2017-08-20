/*

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

*/
template<typename T , class Container=vector<T>, class Compare=less<typename Container::value_type>>
class custom_priority_queue: public priority_queue<T, Container, Compare>{
    public:
    
    bool remove(const T& value){
        auto it = find(this->c.begin(), this->c.end(), value);
        if(it!=this->c.end()){
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }else{
            return false;
        }
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        custom_priority_queue<int, vector<int>, less<int>> cq;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            cq.push(nums[i]);
            //cout<<cq.size()<<endl;
            if(cq.size()==k){
                ret.push_back(cq.top());
                //cout<<nums[i-k+1]<<endl;
                cq.remove(nums[i-k+1]);                
            }                      
        }
        return ret;
    }
};