/*
 *  find all possible combinations -- backtracking
 *  find the number of possible combinations -- dynamic programming
 *
 *  dp[i]: how many possible combinations that whose summation equals to i
 *  runtime: O(target*N)
 */


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++) {
            for(auto num : nums) {
                if(i - num >= 0) {
                    dp[i] = dp[i] + dp[i-num];
                }
            }
        }
        
        return dp[target];
    }
};





/*
 *  backtracking
 *  runtime: O(N^target)
 */


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int counter = 0;
        combinationHelper(counter, target, nums);
        return counter;
    }
    
private:
    void combinationHelper(int& counter, int target, vector<int>& nums) {
        if(target < 0) {
            return;
        }
        
        if(target == 0) {
            counter += 1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            target -= nums[i];
            combinationHelper(counter, target, nums);
            target += nums[i];
        }
    }
};