/*
 *  Dynamic programming
 */


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // edge condition
        if(s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        vector<vector<bool>> table(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        
        // initialization
        table[0][0] = true;
        for(int i = 1; i <= s1.length(); i++) {
            table[i][0] = (s1.substr(0, i) == s3.substr(0, i));
        }
        for(int i = 1; i <= s2.length(); i++) {
            table[0][i] = (s2.substr(0, i) == s3.substr(0, i));
        }
        
        // transfer function
        // table[i][j]: can s1.substr(0, i) and s2.substr(0, j) form s3.substr(0, i+j)
        for(int i = 1; i <= s1.length(); i++) {
            for(int j = 1; j <= s2.length(); j++) {
                
                int k = i + j;
                // s1.substr(0, i-1) and s2.substr(0, j) form s3.substr(0, i+j-1) && s1[i-1] == s3[k-1]
                if(table[i-1][j] == true && s1[i-1] == s3[k-1]) {
                    table[i][j] = true;
                    
                    // s1.substr(0, i) and s2.substr(0, j-1) form s3.substr(0, i+j-1) && s2[j-1] == s3[k-1]
                } else if(table[i][j-1] == true && s2[j-1] == s3[k-1]) {
                    table[i][j] = true;
                    
                    // s1.substr(0, i) and s2.substr(0, j) can not form s3.substr(0, i+j)
                } else {
                    table[i][j] = false;
                }
            }
        }
        
        // results
        return table[s1.length()][s2.length()];
    }
};