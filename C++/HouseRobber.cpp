class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        
        vector<int> money(nums.size(), 0);
        money[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(i == 1) {
                money[i] = max(money[i-1], 0 + nums[i]);
            } else {
                money[i] = max(money[i-1], money[i-2] + nums[i]);
            }
        }
        
        return money.back();
    }
};