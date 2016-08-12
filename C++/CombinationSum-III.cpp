class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> comb;
        combinationHelper(1, 0, n, k, comb, results);
        return results;
    }
    
private:
    void combinationHelper(int idx, int sum, int n, int k, vector<int>& comb, vector<vector<int>>& results) {
        if(comb.size() > k || sum > n) {
            return;
        }
        
        if(comb.size() == k && sum == n) {
            results.push_back(comb);
            return;
        }
        
        for(int i = idx; i <= 9; i++) {
            comb.push_back(i);
            sum += i;
            
            combinationHelper(i + 1, sum, n, k, comb, results);
            
            sum -= i;
            comb.pop_back();
        }
    }
};