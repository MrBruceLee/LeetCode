/*
 *  Reference: https://leetcode.com/discuss/61274/17-line-log-time-space-accepted-easy-solution-explanations
 *  A detailed explanation: https://briangordon.github.io/2014/08/the-skyline-problem.html
 *
 *  Runtime - O(N*log(N))
 *  Space - O(N)
 */


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> corners;
        multimap<int, int> points; // (x, y)
        multiset<int> heights = {0};
        
        for(int i = 0; i < buildings.size(); i++) {
            points.emplace(buildings[i][0], buildings[i][2]); // positive height --> start points
            points.emplace(buildings[i][1], -buildings[i][2]); // negative height --> end points
        }
        
        corners.push_back(make_pair(-1, -1)); // dummy corner
        
        int x = -1;
        int y = 0;
        for(auto point : points) {
            if(x >= 0 && point.first != x && corners.back().second != y) {
                corners.push_back(make_pair(x, y));
            }
            
            if(point.second > 0) {
                heights.insert(point.second);
            } else {
                heights.erase(heights.find(-point.second));
            }
            
            x = point.first;
            y = *heights.rbegin(); // the value of multiset is ordered from small to big
        }
        
        corners.erase(corners.begin()); // erase dummy corner
        
        if(corners.empty() == false) {
            corners.push_back(make_pair(x, 0));
        }
        
        return corners;
    }
};