class Solution {
public:
    int longestValidParentheses(string s) {
        int LVP = 0;
        stack<int> idx; // at the end, the element inside "idx" are the index of parentheses which could not make a pair
        idx.push(-1);
        
        for(int i = 0; i < s.size(); i++) {
            int j = idx.top();
            
            // if can make a pair, recording its relative length
            if(j != -1 && s[j] == '(' && s[i] == ')') {
                idx.pop();
                LVP = max(LVP, i - idx.top());
                
            } else {
                idx.push(i);
            }
        }
        
        return LVP;
    }
};