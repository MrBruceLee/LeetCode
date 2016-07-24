/*
 *  Runtime - O(N^3)
 */


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                
                if(nums[i] >= nums[j]) {
                    continue;
                }
                
                for(int k = j + 1; k < nums.size(); k++) {
                    if(nums[j] < nums[k]) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};



/*
 *  Runtime - O(N)
 *
 *  Track the minimum value and the second minimum value.
 *  If there is a number larger than both min1 and min2, return true.
 *  Else, update min1 and min2
 *
 */


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(int x : nums) {
            if(x <= min1) {
                min1 = x;
            } else if (x <= min2) {
                min2 = x;
            } else {
                return true;
            }
        }
        
        return false;
    }
};