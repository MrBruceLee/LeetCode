class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums; // return value
        bool isPureNum = true; // input is a number or not
        
        for(int i = 0; i < input.size(); i++) {
            // if input[i] is a digit, skip it
            if(isdigit(input[i]) == true) {
                continue;
            }
            
            isPureNum = false;
            
            // divide
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1));
            
            // conquer
            if(input[i] == '+') {
                for(int a : left) {
                    for(int b : right) {
                        nums.push_back(a + b);
                    }
                }
            } else if (input[i] == '-') {
                for(int a : left) {
                    for(int b : right) {
                        nums.push_back(a - b);
                    }
                }
            } else if (input[i] == '*') {
                for(int a : left) {
                    for(int b : right) {
                        nums.push_back(a * b);
                    }
                }
            }
        }
        
        // if input is a number, then push the number into vector
        if(isPureNum == true) {
            nums.push_back(atoi(input.c_str()));
        }
        
        return nums;
    }
};