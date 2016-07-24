/*
 *  Hash Map
 *  Runtime - O(N)
 */


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        int curr_sum = 0; // summation of vector "nums" so far
        int max_len = 0; // maximum length (i.e. the results of this problem)
        
        for(int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            
            // current summation equals k, the the length should be i - (-1) = i + 1. And its the maximum length so far
            if(curr_sum == k) {
                max_len = i + 1;
                
            // "curr_sum - k" is found means there was a summation x which satisfies curr_sum - x = k
            } else {
                if(sums.find(curr_sum - k) != sums.end()) {
                    max_len = max(max_len, i - sums[curr_sum - k]);
                }
            }
            
            // since we want the maximum length, we only keep the smallest index for each summation
            if(sums.find(curr_sum) == sums.end()) {
                sums[curr_sum] = i;
            }
        }
        
        return max_len;
    }
};



/*
 *  The same idea. A little bit simplified solution
 */


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        int curr_sum = 0;
        int max_len = 0;
        
        // init summation 0 at index -1
        sums[0] = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            curr_sum += nums[i];
            
            // do not need to specified the case that "curr_sum == k"
            if(sums.find(curr_sum - k) != sums.end()) {
                max_len = max(max_len, i - sums[curr_sum - k]);
            }
            
            if(sums.find(curr_sum) == sums.end()) {
                sums[curr_sum] = i;
            }
        }
        
        return max_len;
    }
};