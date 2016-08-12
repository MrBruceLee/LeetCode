class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> results;
        vector<int> set;
        subsetsHelper(0, nums, set, results);
        return results;
    }
    
private:
    void subsetsHelper(int idx, vector<int>& nums, vector<int>& set, vector<vector<int>>& results) {
        results.push_back(set);
        
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) {
                continue;
            }
            
            set.push_back(nums[i]);
            subsetsHelper(i + 1, nums, set, results);
            set.pop_back();
        }
    }
};