/*
 *  Runtime O(S*T)
 *  Space O(S*T)
 *
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> table(s.length() + 1, vector<int>(t.length() + 1, 0));
        
        // initialization
        // t = "" is a subsequences of each s.substr(0, i)
        for(int i = 0; i <= s.length(); i++) {
            table[i][0] = 1;
        }
        
        // transfer function
        // table[i][j]: the number of distinct subsequences of t.substr(0, j) in s.substr(0, i)
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= t.length(); j++) {
                
                if(s[i-1] != t[j-1]) {
                    table[i][j] = table[i-1][j];
                    
                } else {
                    table[i][j] = table[i-1][j-1] + table[i-1][j];
                }
            }
        }
        
        // results
        return table[s.length()][t.length()];
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
        vector<int> table(t.length() + 1, 0);
        
        // initialization
        // t = "" is a subsequences of s = ""
        table[0] = 1;
        
        // transfer function
        for(int i = 1; i <= s.length(); i++) {
            // tmp records current row's state, while table has previous row's state
            vector<int> tmp(t.length() + 1);
            
            for(int j = 1; j <= t.length(); j++) {
                
                if(s[i-1] != t[j-1]) {
                    tmp[j] = table[j];
                    
                } else {
                    tmp[j] = table[j] + table[j-1];
                }
            }
            
            table = tmp;
            // t = "" is a subsequences of s.substr(0, i)
            table[0] = 1;
        }
        
        // results
        return table[t.length()];
    }
    
};