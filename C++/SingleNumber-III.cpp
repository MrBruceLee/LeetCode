/*
 *  Hash Table
 *  Runtime: O(N)    Space: O(N)
 */


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int num : nums) {
            mp[num]++;
        }
        
        vector<int> theNumbers;
        for(auto e : mp) {
            if(e.second != 2) {
                theNumbers.push_back(e.first);
            }
        }
        
        return theNumbers;
    }
};



/*
 *  Bit Manipulation
 *  Runtime: O(N)    Space: O(1)
 */


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a_xor_b = 0;
        for(int num : nums) {
            a_xor_b ^= num;
        }
        
        // Because a and b are different numbers, a xor b will not equals 0.
        // That means, there must be at least one bit in a_xor_b equals 1.
        // At that bit, a and b must be different.
        // So that, we can split the array into two arrays based on whether that bit equals 0 or 1.
        // Then, apply xor on each array seperately, the outcome of each array will be final results.
        int bitIdx; // the first bit in a_xor_b that equals 1
        int tmp;
        for(int i = 0; i < 32; i++) {
            tmp = a_xor_b;
            if( ((tmp >> i)) & 1 == 1) {
                bitIdx = i;
                break;
            }
        }
        
        vector<int> theNumbers(2, 0);
        for(int num : nums) {
            if( ((num >> bitIdx) & 1) == 0) {
                theNumbers[0] ^= num;
            } else {
                theNumbers[1] ^= num;
            }
        }
        
        return theNumbers;
    }
};