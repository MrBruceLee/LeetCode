/*
 *  Dynamic Programming
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        
        for(int i = 0; i <= n1; i++) {
            for(int j = 0; j <= n2; j++) {
                // dp[0][0] = true  --> "" + "" == ""
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                    
                    // the s1 == ""
                } else if(i == 0) {
                    dp[i][j] = ( dp[i][j-1] && (s2[j-1] == s3[i+j-1]) );
                    
                    // the s2 == ""
                } else if(j == 0) {
                    dp[i][j] = ( dp[i-1][j] && (s1[i-1] == s3[i+j-1]) );
                    
                } else {
                    dp[i][j] = ( (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]) );
                    
                }
            }
        }
        
        return dp[n1][n2];
    }
};