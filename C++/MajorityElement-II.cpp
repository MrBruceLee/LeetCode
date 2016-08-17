/*
 *  Hash Table
 *  Runtime: O(N)    Space: O(N)
 */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int num : nums) {
            mp[num]++;
        }
        
        vector<int> majority;
        for(auto e : mp) {
            if(e.second > nums.size() / 3) {
                majority.push_back(e.first);
            }
        }
        
        return majority;
    }
};



/*
 *  Similar with MajorityElement.cpp
 *  Runtime: O(N)    Space: O(1)
 */


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1;
        int num2;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == num1) {
                cnt1++;
            } else if (nums[i] == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for(auto num : nums) {
            if(num1 == num) {
                cnt1++;
            } else if (num2 == num) {
                cnt2++;
            }
        }
        
        vector<int> majority;
        if(cnt1 > nums.size() / 3) {
            majority.push_back(num1);
        }
        if (cnt2 > nums.size() / 3) {
            majority.push_back(num2);
        }
        
        return majority;
    }
};