class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        permuteHelper(0, nums, results);
        return results;
    }
    
private:
    void permuteHelper(int idx, vector<int>& nums, vector<vector<int>>& results) {
        if(idx == nums.size() - 1) {
            results.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            permuteHelper(idx + 1, nums, results);
            swap(nums[idx], nums[i]);
        }
    }
};