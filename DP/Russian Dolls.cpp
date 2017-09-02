/*

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


Sort the array. Ascend on width and descend on height if width are same.
Find the longest increasing subsequence based on height.
*/
struct envelope{
    bool operator()(const pair<int, int>& a, const pair<int,int>& b){
        if(a.first < b.first)
            return true;
        else if(a.first == b.first)
            return b.second < a.second;
        else
            return false;
    }
};
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {        
        if(envelopes.size()<=1)
            return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), envelope());
        int count[envelopes.size()];
        int maxi = 0;
        fill(count, count+envelopes.size(), 1);
        for(int i = 1;i<envelopes.size();i++){
            for(int j=0;j<i;j++){
                if(envelopes[i].second > envelopes[j].second)
                    count[i] = max(count[j]+1, count[i]);
            }
            maxi = max(count[i], maxi);
        }
        return maxi;
    }
};