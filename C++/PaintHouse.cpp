/*
 *  dp[i][j] = min(dp[i-1][0], dp[i-2][1], ...., dp[i-1][j-1], dp[i-1][j+1], ...) + costs[i][j]
 *
 *  If paiting house i by using color j, we can find the minimum cost of painting house from 0 to i-1 among all color except j.
 *  Add the minimum cost with the cost of house i by using color j.
 *
 *  runtime - O(K*N)  k = number of colors
 *  space - O(K*N)
 *
 */

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        
        for(int i = 1; i < n; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }
        
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};



/*
 *  runtime - O(K*N)  k = number of colors
 *  space - O(K)
 */

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        
        vector<int> dp(3, 0);
        dp[0] = costs[0][0];
        dp[1]  = costs[0][1];
        dp[2] = costs[0][2];
        
        for(int i = 1; i < n; i++){
            vector<int> color = dp;
            dp[0] = min(color[1], color[2]) + costs[i][0];
            dp[1] = min(color[0], color[2]) + costs[i][1];
            dp[2] = min(color[0], color[1]) + costs[i][2];
        }
        
        return min(dp[0], min(dp[1], dp[2]));
    }
};



/*
 *  The same idea. 
 *  Solved in space, but I don't think it is a good solution
 *
 */

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if( n == 0) return 0;
        
        for(int i = 1; i < n; i++) {
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
        }
        
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};