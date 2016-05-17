/*
 *  http://liangjiabin.com/blog/2015/04/leetcode-best-time-to-buy-and-sell-stock.html
 *  Runtime - O(NK)
 *  Space - O(NK)
 *
 */


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() == true){
            return 0;
        }
        
        int n = prices.size();
        
        // if k > n, do it like "Best Time to Buy and Sell Stock II" is more efficient.
        if(k > n){
            return maxProfit2(prices);
        }
        
        cout << n << endl;
        vector<vector<int>> local(n, vector<int>(k + 1, 0));
        vector<vector<int>> globle(n, vector<int>(k + 1, 0));
        
        for(int i = 1; i < n; i++){
            int diff = prices[i] - prices[i-1];
            
            for(int j = 1; j <= k; j++){
                local[i][j] = max(globle[i-1][j-1], local[i-1][j] + diff);
                globle[i][j] = max(globle[i-1][j], local[i][j]);
            }
        }
        
        return globle[n-1][k];
    }
    
private:
    int maxProfit2(vector<int>& prices){
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};


/*
 *  Runtime - O(NK)
 *  Space - O(K)
 *
 */


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty() == true){
            return 0;
        }
        
        int n = prices.size();
        
        if(k > n){
            return maxProfit2(prices);
        }
        
        cout << n << endl;
        vector<int> local(k + 1);
        vector<int> globle(k + 1);
        
        for(int i = 1; i < n; i++){
            int diff = prices[i] - prices[i-1];
            
            /** THE MAIN DIFFERENCES **/
            for(int j = k; j > 0; j--){
                local[j] = max(globle[j-1], local[j] + diff);
                globle[j] = max(globle[j], local[j]);
            }
            /** END **/
        }
        
        return globle[k];
    }
    
private:
    int maxProfit2(vector<int>& prices){
        int profit = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};