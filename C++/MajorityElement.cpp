/*
 *  Hash Table
 *  Runtime: O(N)    Space: O(N)
 */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto num : nums) {
            mp[num]++;
        }
        
        int majority;
        for(auto e : mp) {
            if(e.second > nums.size() / 2) {
                majority = e.first;
                break;
            }
        }
        
        return majority;
    }
};




/*
 *  Increase counter by 1 when nums[i] == majority, otherwise, decrease counter by 1.
 *  Every time, when counter decresed to 0, replace the majority number by nums[i].
 *
 *  Runtime: O(N)    Space: O(1)
 */


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int cnt = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == majority) {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            
            if(cnt == 0) {
                majority = nums[i];
                cnt = 1;
            }
        }
        
        return majority;
    }
};