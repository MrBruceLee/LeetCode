/*
 *  If nums[i] makes currSum < 0, it indicates previous array (including i) will only decrease the sum of successor array. In that case, we can to ignore the previosu array by set currSum ＝ 0.
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0) {
                currSum = 0;
            }
        }
        
        return maxSum;
    }
};