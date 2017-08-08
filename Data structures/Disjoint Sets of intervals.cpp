/*Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?

 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    vector<Interval> intervals;
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        bool found = false;
        Interval inter;
        inter.start = val;
        inter.end = val;
        //cout<<val<<endl;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].start>val){
                if(i==0){
                    if(intervals[i].start==val+1)
                        intervals[i].start = val;
                    else
                        intervals.insert(intervals.begin(), inter );
                    found = true;
                }else if(intervals[i-1].end >= val || intervals[i-1].end == val-1){
                    if(intervals[i].start == val+1){
                        intervals[i-1].end = intervals[i].end;
                        intervals.erase(intervals.begin()+i);
                    }else{
                        intervals[i-1].end = max(intervals[i-1].end, val);
                    }
                    found = true;
                }else if(intervals[i].start == val+1){
                    intervals[i].start = val;
                    found = true;
                }else{
                    intervals.insert(intervals.begin()+i, inter);
                    found = true;
                }
               // cout<<i<<endl;
            }
        }
        if(!found){
            if(intervals.size() >0 && (intervals[intervals.size()-1].end >= val ||
                                       intervals[intervals.size()-1].end == val-1))
                intervals[intervals.size()-1].end = max(intervals[intervals.size()-1].end, val);
            else
                intervals.push_back(inter);
        }
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */