class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int num : nums1) {
            mp[num] = 1;
        }
        
        vector<int> results;
        for(int num : nums2) {
            if(mp.find(num) != mp.end() && mp[num] != 0) {
                results.push_back(num);
                mp[num] = 0;
            }
        }
        
        return results;
    }
};