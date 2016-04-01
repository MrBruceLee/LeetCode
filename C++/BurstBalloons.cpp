class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for(int i = 1; i < len; i++){
            for(int lo = 0; lo < len-i; lo++){
                int hi = lo+i;
                for(int k = lo+1; k < hi; k++){
                    dp[lo][hi] = max(dp[lo][hi], nums[lo]*nums[k]*nums[hi] + dp[lo][k] + dp[k][hi]);
                }
            }
        }
        return dp[0][len-1];
    }
};