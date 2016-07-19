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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), cmpfunc);
        
        vector<Interval> rooms;
        rooms.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            
            int j;
            for(j = 0; j < rooms.size(); j++) {
                if(rooms[j].end <= intervals[i].start) {
                    rooms[j] = intervals[i];
                    break;
                }
            }
            
            if(j == rooms.size()) {
                rooms.push_back(intervals[i]);
            }
        }
        
        return rooms.size();
    }
    
private:
    bool static cmpfunc(Interval& a, Interval& b) {
        return a.start < b.start;
    }
};