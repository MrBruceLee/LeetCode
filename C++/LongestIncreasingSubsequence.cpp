/*
 *  Dynamic Programming 
 *  Runtime - O(N^2)
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int maxLIS = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            maxLIS = max(maxLIS, dp[i]);
        }
        
        return maxLIS;
    }
};