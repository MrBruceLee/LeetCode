/*
 *  Hash Table
 *  Runtime: O(N)    Space: O(N)
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int num : nums) {
            mp[num]++;
        }
        
        int theNumber;
        for(auto e : mp) {
            if(e.second == 1) {
                theNumber = e.first;
                break;
            }
        }
        
        return theNumber;
    }
};



/*
 *  Bit Manipulation
 *  Runtime: O(N)    Space: O(1)
 */


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int theNumber = 0;
        
        for(int num : nums) {
            theNumber ^= num;
        }
        
        return theNumber;
    }
};