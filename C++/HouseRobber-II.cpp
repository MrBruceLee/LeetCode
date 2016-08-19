class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        vector<int> money(nums.size(), 0);
        
        // rob from the first house
        money[0] = nums[0];
        money[1] = nums[0];
        for(int i = 2; i < nums.size() - 1; i++) {
            money[i] = max(money[i-1], money[i-2] + nums[i]);
        }
        int rob1 = money[nums.size() - 2];
        
        // rob from the second house
        money[0] = 0;
        money[1] = nums[1];
        for(int i = 2; i < nums.size(); i++) {
            money[i] = max(money[i-1], money[i-2] + nums[i]);
        }
        int rob2 = money[nums.size() - 1];
        
        return max(rob1, rob2);
    }
};