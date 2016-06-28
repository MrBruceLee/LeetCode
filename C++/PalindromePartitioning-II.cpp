class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // number of cuts for the first i characters
        vector<int> cuts(n + 1);
        for(int i = 0; i < n + 1; i++) {
            cuts[i] = i - 1;
        }
        
        for(int i = 0; i < n; i++) {
            // odd palindrome
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++) {
                // 0    [1    2    3    4    5]    6    7
                //       (i-j)     i               (i+j)+1
                cuts[(i+j) + 1] = min(cuts[(i-j)] + 1, cuts[(i+j) + 1]);
            }
            // even palindrome
            for(int j = 0; i-j >= 0 && i+j+1 < n && s[i-j] == s[i+j+1]; j++) {
                // 0    [1    2    3    4    5    6]    7
                //       (i-j)     i                    (i+j+1)+1
                cuts[(i+j+1) + 1] = min(cuts[(i-j)] + 1, cuts[(i+j+1) + 1]);
            }
        }
        
        return cuts.back();
    }
};