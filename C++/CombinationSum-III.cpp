class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> comb;
        combinationHelper(1, n, k, comb, results);
        return results;
    }
    
private:
    void combinationHelper(int idx, int n, int k, vector<int>& comb, vector<vector<int>>& results) {
        if(comb.size() > k || n < 0) {
            return;
        }
        
        if(comb.size() == k && n == 0) {
            results.push_back(comb);
            return;
        }
        
        for(int i = idx; i <= 9; i++) {
            comb.push_back(i);
            n -= i;
            
            combinationHelper(i + 1, n, k, comb, results);
            
            n += i;
            comb.pop_back();
        }
    }
    
};