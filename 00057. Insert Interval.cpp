
//	Accepted	20 ms	cpp
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size() < 1){
            return vector<Interval>{newInterval};
        }
        Interval tmp(-1,-1);
        bool mark = false;
        for_each(intervals.begin(), intervals.end(), [&](Interval obj){
            if(tmp.start == -1){
                tmp.start = this->judge(newInterval.start, obj) ? obj.start : -1;
            }
            
            if(tmp.end == -1){
                tmp.end = this->judge(newInterval.end, obj) ? obj.end  : -1;
            }
            
            if(tmp.start == obj.start && tmp.end == obj.end) mark = true;
        });
        if(mark) return intervals;
        tmp.start = tmp.start == -1 ? newInterval.start : tmp.start;
        tmp.end = tmp.end == -1 ? newInterval.end : tmp.end;
        
        bool flag = false;
        vector<Interval> res = vector<Interval>();
        for_each(intervals.begin(), intervals.end(), [&](Interval obj){
            if(flag){
                res.push_back(obj);
            }
            else{
                if(obj.start >= tmp.start && obj.end <= tmp.end) return;
                
                if(obj.start > tmp.end){
                    flag = true;
                    res.push_back(tmp);
                }
                res.push_back(obj);
            }
        });
        if(!flag) res.push_back(tmp);
        return res;
    }
    bool judge(const int num, const Interval interval){
        if(num >= interval.start && num <= interval.end)
            return true;
        return false;
    }
};
