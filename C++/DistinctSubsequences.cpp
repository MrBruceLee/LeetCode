/*
 *  excellent explaination:
 *  https://leetcode.com/discuss/26680/easy-to-understand-dp-in-java
 *
 *  Runtime O(S*T)
 *  Space O(S*T)
 *
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int lenT = t.size();
        int lenS = s.size();
        
        vector<vector<int>> dp(lenT+1, vector<int>(lenS+1, 0));
        
        for(int i = 0; i <= lenS; i++) dp[0][i] = 1;
        
        for(int i = 1; i <= lenT; i++){
            for(int j = 1; j <= lenS; j++){
                
                if(t[i-1] == s[j-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
                
                // ==> dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        
        return dp[lenT][lenS];
    }
};



/*
 *  Since we only care the previous one state, we only need to maitian the previous one row
 *
 *  Runtime - O(S*T)
 *  Space - O(S)
 *
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int lenT = t.size();
        int lenS = s.size();
        
        vector<int> dp(lenS+1, 1);
        
        for(int i = 1; i <= lenT; i++){
            
            vector<int> temp(lenS+1, 0);
            
            for(int j = 1; j <= lenS; j++){
                
                if(t[i-1] == s[j-1])
                    temp[j] = temp[j-1] + dp[j-1];
                else
                    temp[j] = temp[j-1];
                
                // ==> temp[j] = temp[j-1] + (t[i-1] == s[j-1] ? dp[j-1] : 0);
            }
            
            dp = temp;
        }
        
        return dp[lenS];
    }
};