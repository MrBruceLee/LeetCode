class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        for(int num : nums1) {
            mp[num]++;
        }
        
        vector<int> results;
        for(int num : nums2) {
            if(mp.find(num) != mp.end() && mp[num] > 0) {
                results.push_back(num);
                mp[num]--;
            }
        }
        
        return results;
    }
};