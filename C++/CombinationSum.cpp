class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            comb.push_back(candidates[i]);
            sum += candidates[i];
            
            combinationHelper(i, sum, target, comb, candidates, results);
            
            sum -= candidates[i];
            comb.pop_back();
        }
    }
};