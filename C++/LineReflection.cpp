class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, vector<int>> mp;
        for(auto point : points) {
            mp[point.second].push_back(point.first);
        }
        
        double mid = 0;
        for(auto e : mp) {
            int front = 0;
            int end = e.second.size() - 1;
            sort(e.second.begin(), e.second.end());
            
            while(front <= end) {
                double curr_mid = (double)(e.second[front] + e.second[end]) / 2.0;
                if(mid == 0) {
                    mid = curr_mid;
                } else {
                    if(curr_mid != mid) {
                        return false;
                    }
                }
                front++;
                end--;
            }
        }
        
        return true;
    }
};