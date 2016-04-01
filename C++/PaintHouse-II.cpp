/*
 *  See "256. Paint House" for "runtime O(K*N), space O(K*N)" solution
 *  https://leetcode.com/problems/paint-house/
 *
 *  runtime - O(K*N)
 *  space - O(K)
 *
 */

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        
        int n = costs.size();
        int k = costs[0].size();
        
        vector<int> dp(k, 0);
        int min1 = 0, min2 = 0;
        
        for(int i = 0; i < n; i++) {
            int prev_min1 = min1, prev_min2 = min2;
            min1 = INT_MAX; min2 = INT_MAX;
            
            for(int j = 0; j < k; j++) {
                if(dp[j] != prev_min1) {
                    dp[j] = prev_min1 + costs[i][j];
                } else {
                    dp[j] = prev_min2 + costs[i][j];
                }
                
                if(dp[j] < min1) {
                    min2 = min1;
                    min1 = dp[j];
                } else if(dp[j] < min2){
                    min2 = dp[j];
                }
            }
        }
        
        
        return min1;
    }
};


/*
 *  runtime - O(K*N)
 *  space - O(1)
 *
 */

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        
        int n = costs.size();
        int k = costs[0].size();
        
        int min1 = 0, min2 = 0;
        int color1 = -1;
        
        for(int i = 0; i < n; i++){
            int prev_min1 = min1, prev_min2 = min2;
            int prev_color1 = color1;
            min1 = INT_MAX; min2 = INT_MAX;
            
            for(int j = 0; j < k; j++){
                int cost;
                if(j != prev_color1){
                    cost = prev_min1 + costs[i][j];
                }else{
                    cost = prev_min2 + costs[i][j];
                }
                
                if(cost < min1){
                    min2 = min1;
                    min1 = cost;
                    color1 = j;
                }else if(cost < min2){
                    min2 = cost;
                }
            }
        }
        
        return min1;
    }
};