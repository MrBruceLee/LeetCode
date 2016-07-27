/*
 *  Greedy
 *  Runtime - O(N)  Space - O(1)
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxLen) {
                return false;
            }
            
            maxLen = max(maxLen, i + nums[i]);
        }
        
        return true;
    }
};




/*
 *  Dynamic Programming
 *  Runtime - O(N^2)    Space - O(N)
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> can(nums.size(), false);
        can[0] = true;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i - 1; j >= 0; j--) { // optimize for the test case: [1,1,1,1,1,......,1,1,1,1,1]
            // for(int j = 0; j < i; j++) {
                
                if(can[j] == true && j + nums[j] >= i) {
                    can[i] = true;
                    break;
                }
            }
        }
        
        return can.back();
    }
};