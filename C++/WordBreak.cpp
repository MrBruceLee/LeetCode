class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] == false) {
                    continue;
                }
                
                string tar = s.substr(j, i-j);
                if(wordDict.find(tar) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp.back();
    }
};