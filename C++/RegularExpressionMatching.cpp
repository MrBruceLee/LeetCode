// recursion - 644ms

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty() == true) {
            return s.empty();
        }
        
        if(p.size() > 1 && p[1] == '*') {
            return ( isMatch(s, p.substr(2)) || (s.empty() == false) && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p) );
            
        }else {
            return ( (s.empty() == false) && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)) );
            
        }
    }
};



// dynamic programming - 16ms

/*
 * f[i][j]: if s[0..i-1] matches p[0..j-1]
 *
 * if p[j - 1] != '*'
 *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
 *
 * if p[j - 1] == '*', denote p[j - 2] with x
 *      f[i][j] is true iff any of the following is true
 *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
 *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
 *
 * '.' matches any single character
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));
        
        // dp[i][j]: if s[0..i-1] matches p[0..j-1]
        dp[0][0] = true;
        
        // p matches ""
        for(int j = 1; j <= pSize; j++) {
            dp[0][j] = (j > 1) && (p[j-1] == '*') && (dp[0][j-2] == true);
        }
        
        for(int i = 1; i <= sSize; i++) {
            for(int j = 1; j <= pSize; j++) {
                if(p[j-1] != '*') {
                    dp[i][j] = (dp[i-1][j-1] == true) && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else {
                    dp[i][j] = (dp[i][j-2] == true) || dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.');
                }
            }
        }
        
        return dp[sSize][pSize];
    }
};