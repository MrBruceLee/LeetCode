/*
 *  If pass reference of nums, we will get wrong results
 *  e.g. [1,1,2,2] -- Because "1" swaps with the first "2" and the second "2" will produce the same permutation
 */


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> results;
        permuteHelper(0, nums, results);
        return results;
    }
    
private:
    void permuteHelper(int idx, vector<int> nums, vector<vector<int>>& results) {
        if(idx == nums.size() - 1) {
            results.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[idx]) {
                continue;
            }
            
            swap(nums[idx], nums[i]);
            permuteHelper(idx + 1, nums, results);
        }
    }
};