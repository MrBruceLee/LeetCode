/*
 *  Runtime: O(K * N)
 */

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> results(length, 0);
        
        for(int i = 0; i < updates.size(); i++) {
            for(int j = updates[i][0]; j <= updates[i][1]; j++) {
                results[j] += updates[i][2];
            }
        }
        
        return results;
    }
};


/*
 *  Runtime: O(K + N)
 *
 *  Explanation: https://discuss.leetcode.com/topic/53142/detailed-explanation-if-you-don-t-understand-especially-put-negative-inc-at-endindex-1
 */

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> results(length + 1, 0);
        
        for(int i = 0; i < updates.size(); i++) {
            results[updates[i][0]] += updates[i][2];
            results[updates[i][1] + 1] -= updates[i][2];
        }
        
        for(int i = 1; i < results.size(); i++) {
            results[i] += results[i-1];
        }
        
        results.pop_back();
        return results;
    }
};