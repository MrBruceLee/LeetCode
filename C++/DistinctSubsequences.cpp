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
        table[0][0] = 1;
        table[1][0] = 1;
        
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
 *  Space - O(S) - achieved by "rolling array"
 *
 */


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> table(2, vector<int>(t.length() + 1, 0));
        
        // initialization
        // t = "" is a subsequences of each s.substr(0, i)
        for(int i = 0; i < 2; i++) {
            table[i][0] = 1;
        }
        
        // transfer function
        // table[i][j]: the number of distinct subsequences of t.substr(0, j) in s.substr(0, i)
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= t.length(); j++) {
                
                if(s[i-1] != t[j-1]) {
                    table[i%2][j] = table[(i-1)%2][j];
                    
                } else {
                    table[i%2][j] = table[(i-1)%2][j-1] + table[(i-1)%2][j];
                }
            }
        }
        
        // results
        return table[(s.length())%2][t.length()];
    }
    
};