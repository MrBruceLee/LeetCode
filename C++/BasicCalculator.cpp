/*
 *  My solution is not the optimal one
 */

class Solution {
public:
    int calculate(string s) {
        s.insert(s.begin(), '(');
        s.push_back(')');
        
        stack<int> nums;
        stack<char> ops;
        
        for(int i = 0; i < s.size(); i++) {
            // parse number
            if(isdigit(s[i]) == true) {
                int num = 0;
                while(isdigit(s[i]) == true) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
                i--;
                
                // skip space
            } else if (s[i] == ' '){
                
                // calculate
            } else {
                if(s[i] == '+' || s[i] == '-' || s[i] == '(') {
                    ops.push(s[i]);
                }
                
                if(s[i] == ')') {
                    while(ops.top() != '(') {
                        int b = nums.top();
                        nums.pop();
                        int a = nums.top();
                        nums.pop();
                        
                        if(ops.top() == '-') {
                            b = -b;
                        }
                        ops.pop();
                        
                        if(ops.top() == '-') {
                            a = -a;
                            ops.top() = '+';
                        }
                        
                        nums.push(a + b);
                    }
                    
                    ops.pop(); // pop out '('
                }
            }
        }
        
        return nums.top();
    }
};