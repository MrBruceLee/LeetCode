/*
 *  For me, it's hard to understand......
 *  https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
 *
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};