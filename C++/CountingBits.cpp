/*
 *  Bit Manipulation
 *  Runtime: O(N * sizeof(int))
 */


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ones(num + 1, 0);
        ones[0] = 0;
        
        for(int i = 1; i <= num; i++) {
            int cnt = 0;
            int currNumber = i;
            while(currNumber > 0) {
                if( currNumber & 1 == 1) {
                    cnt++;
                }
                currNumber /= 2;
            }
            ones[i] = cnt;
        }
        
        return ones;
    }
};




/*
 *  Dynamic Programming
 *  Runtime: O(N)
 */


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ones(num + 1, 0);
        ones[0] = 0;
        
        for(int i = 1; i <= num; i++) {
            if(i % 2 == 1) {
                ones[i] = ones[i-1] + 1;
            } else {
                ones[i] = ones[i >> 1];
            }
        }
        
        return ones;
    }
};



