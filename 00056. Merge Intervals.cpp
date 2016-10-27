
//Accepted	19 ms	cpp
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() < 1) return vector<Interval>();
        sort(intervals.begin(), intervals.end(), [&](const Interval& a,const Interval& b){
            if(a.start == b.start){
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        vector<Interval> ans;
        Interval interval(intervals[0].start,intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            if(judge(interval, intervals[i])){
                ans.push_back(interval);
                interval = Interval(intervals[i].start,intervals[i].end);
            }
            else{
                interval.start = min(interval.start, intervals[i].start);
                interval.end = max(interval.end,intervals[i].end);
            }
        }
        ans.push_back(interval);
        return ans;
    }
    bool judge(const Interval& a,const Interval& b){
        if(a.end < b.start || b.end < a.start) return true;
        return false;
    }
};
