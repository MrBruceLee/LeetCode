class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> comb;
        combinationHelper(0, target, comb, candidates, results);
        return results;
    }
    
private:
    void combinationHelper(int idx, int target, vector<int>& comb, vector<int>& candidates, vector<vector<int>>& results) {
        if(target < 0) {
            return;
        }
        
        if(target == 0) {
            results.push_back(comb);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            target -= candidates[i];
            
            combinationHelper(i, target, comb, candidates, results);
            
            target += candidates[i];
            comb.pop_back();
        }
    }
    
};