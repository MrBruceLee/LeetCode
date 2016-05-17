/*
 *  Runtime - O(N)
 *  Space - O(N)
 *
 *  Here we maintain two vectors, preProfit and posProfit, respectively.
 *  preProfit[i] is the maximum profit before the i-th day, while posProfit store the maximum profit after the i-th day.
 *  So that, the answer would be max( preProfit[i] + posProfit[i] ).
 *
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() == true){
            return 0;
        }
        
        int n = prices.size();
        vector<int> preProfit(n, 0);
        vector<int> posProfit(n, 0);
        
        int buyPrice = prices[0];
        for(int i = 1; i < n; i++){
            if(buyPrice > prices[i]){
                buyPrice = prices[i];
            }
            preProfit[i] = max(preProfit[i-1], prices[i] - buyPrice);
        }
        
        int sellPrice = prices[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(sellPrice < prices[i]){
                sellPrice = prices[i];
            }
            posProfit[i] = max(posProfit[i+1], sellPrice - prices[i]);
        }
        
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            maxProfit = max(maxProfit, preProfit[i] + posProfit[i]);
        }
        
        return maxProfit;
    }
};