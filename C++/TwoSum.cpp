class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            if(mp.find(diff) != mp.end()) {
                result.push_back(mp[diff]);
                result.push_back(i);
                // since the answer is unique, we can return here
                return result;
                
            } else {
                mp[nums[i]] = i;
            }
        }
        
        return result;
    }
};