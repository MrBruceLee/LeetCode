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
            if(e.second != 3) {
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
        int bits[32] = {0};
        
        for(int num : nums) {
            for(int i = 0; i < 32; i++) {
                if((num >> i) & 1 == 1) {
                    bits[i] += 1;
                }
            }
        }
        
        int theNumber = 0;
        for(int i = 0; i < 32; i++) {
            if(bits[i] % 3 != 0) {
                theNumber |= (1 << i);
            }
        }
        
        return theNumber;
    }
};