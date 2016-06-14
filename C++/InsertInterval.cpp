/*
 *  runtime - O(N)
 *  space - O(N)
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        res.push_back(newInterval);
        
        for(auto curr : intervals){
            Interval newInter = res.back();
            res.pop_back();
            
            // current interval smaller than newInterval
            if(curr.end < newInter.start){
                res.push_back(curr);
                res.push_back(newInter);
                
                // current interval greater than newInterval
            }else if(curr.start > newInter.end){
                res.push_back(newInter);
                res.push_back(curr);
                
                // current interval overlap with newInterval
            }else{
                newInter.start = min(curr.start, newInter.start);
                newInter.end = max(curr.end, newInter.end);
                res.push_back(newInter);
            }
        }
        
        return res;
    }
};