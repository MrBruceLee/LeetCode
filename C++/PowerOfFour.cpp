/*
 *  1         1
 *  4       100
 *  16    10000
 *  64  1000000
 *
 *  Their binary form is a '1' followed by even number of '0's.
 */


class Solution {
public:
    bool isPowerOfFour(int num) {
        int ones = 0;
        int zeros = 0;
        
        for(int i = 31; i >= 0; i--) {
            if( (num >> i) & 1 == 1) {
                ones++;
            } else {
                if(ones == 1) {
                    zeros++;
                }
            }
        }
        
        if(ones == 1 && zeros % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }
};