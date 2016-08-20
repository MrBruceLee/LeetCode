class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        
        vector<pair<int, int>> freq;
        for(auto e : mp) {
            freq.push_back(make_pair(e.second, e.first));
        }
        
        sort(freq.begin(), freq.end(), compfunc);
        
        vector<int> results(k, 0);
        for(int i = 0; i < k; i++) {
            results[i] = freq[i].second;
        }
        
        return results;
    }
    
private:
    bool static compfunc(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};