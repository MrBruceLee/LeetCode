/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct compfunc{
    bool operator()(const Interval& a, const Interval& b) {
        return (a.start < b.start) || (a.start == b.start && a.end < b.end);
    }
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval interval(val, val);
        
        if(tree.empty() == true) {
            tree.insert(interval);
            return;
        }
        
        auto lb = tree.lower_bound(interval);
        if(lb != tree.begin()) {
            if(prev(lb)->end + 1 >= val) {
                interval.start = prev(lb)->start;
                interval.end = max(prev(lb)->end, val);
                tree.erase(prev(lb));
            }
        }
        if(lb != tree.end()) {
            if(lb->start - 1 <= val) {
                interval.start = min(lb->start, interval.start);
                interval.end = lb->end;
                tree.erase(lb);
            }
        }
        
        tree.insert(interval);
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(tree.begin(), tree.end());
    }
    
private:
    set<Interval, compfunc> tree;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */