class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            steps -= 1;
            
            if(steps < 0){
                return false;
            }
            
            // greedy
            steps = max(steps, nums[i]);
        }
        
        return true;
    }
};