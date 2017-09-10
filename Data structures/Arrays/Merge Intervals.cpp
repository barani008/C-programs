/**

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    
    struct sort_interval{
        bool operator()(const Interval& a, const Interval& b){
            if(a.start<b.start)
                return true;
            else if(a.start>b.start)
                return false;
            else{
                return a.end<b.end;
            }
        }
    };
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()==0)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});  
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start > res.back().end)
                res.push_back(intervals[i]);
            else{
                res.back().end = max(res.back().end , intervals[i].end);
            }
        }
        return res;
    }
};