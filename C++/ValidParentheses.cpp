class Solution {
public:
    bool isValid(string s) {
        stack<char> p; // parentheses
        
        for(auto c : s) {
            if(c == '(' || c == '[' || c == '{') {
                p.push(c);
                
            } else {
                if(p.empty() == true) {
                    return false;
                    
                } else if(p.top() == '(' && c == ')' ||
                          p.top() == '[' && c == ']' ||
                          p.top() == '{' && c == '}') {
                    p.pop();
                    
                } else {
                    return false;
                    
                }
            }
        }
        
        return p.empty();
    }
};





