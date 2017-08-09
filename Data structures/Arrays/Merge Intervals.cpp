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
        sort(intervals.begin(), intervals.end(), sort_interval());        
        for(int i=0;i<intervals.size()-1;){
            int end = i+1;
            if(intervals[i].end >= intervals[end].start){
                while(end<intervals.size() && intervals[i].end >= intervals[end].end){
                    end++;
                }
                if(end==intervals.size()){
                    for(int j=end-1;j>=i+1;j--)
                        intervals.erase(intervals.begin()+j);
                }else if(intervals[i].end >= intervals[end].start){
                    intervals[i].end = intervals[end].end;
                    for(int j=end;j>i;j--)
                        intervals.erase(intervals.begin()+j);
                }else{
                    for(int j=end-1;j>i;j--)
                        intervals.erase(intervals.begin()+j);
                }
            }else{
                i++;
            }
        }
        return intervals;
    }
};