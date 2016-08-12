/*
 *  Simlilar with "90. Subsets II"
 *  https://leetcode.com/problems/subsets-ii/
 */


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> results;
        vector<int> comb;
        combinationHelper(0, 0, target, comb, candidates, results);
        return results;
    }
    
private:
    void combinationHelper(int idx, int sum, int target, vector<int>& comb, vector<int>& candidates, vector<vector<int>>& results) {
        if(sum > target) {
            return;
        }
        
        if(sum == target) {
            results.push_back(comb);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            comb.push_back(candidates[i]);
            sum += candidates[i];
            
            combinationHelper(i + 1, sum, target, comb, candidates, results);
            
            sum -= candidates[i];
            comb.pop_back();
        }
    }
};