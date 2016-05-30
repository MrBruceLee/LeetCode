class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for(int i = 1; i <= num.size(); i++){
            string s = num.substr(0, i);
            long val = stol(s);
            
            // if it starts with multiyple 0s, skip them all
            if(to_string(val).size() != s.size()){
                continue;
            }
            
            formula(res, num, target, i, s, val, val, '#');
        }
        
        return res;
    }
    
private:
    void formula(vector<string>& res, string num, int target, int idx, string expression, long val, long preNum, char op) {
        
        //if we reach end of string and left value equals target
        if(idx == num.size() && val == target){
            res.push_back(expression);
            return;
        }
        
        for(int i = idx + 1; i <= num.size(); i++){
            string curS = num.substr(idx, i - idx);
            long curNum = stol(curS);
            
            if(to_string(curNum).size() != curS.size()){
                continue;
            }
            
            //operator between left and right is "+"
            formula(res, num, target, i, expression + "+" + curS, val + curNum, curNum, '+');
            
            //operator between left and right is "-"
            formula(res, num, target, i, expression + "-" + curS, val - curNum, curNum, '-');
            
            //operator between left and right is "*"
            long newVal = 0;
            if(op == '+'){
                newVal = val - preNum + preNum * curNum;
            }else if(op == '-'){
                newVal = val + preNum - preNum * curNum;
            }else{
                newVal = preNum * curNum;
            }
            formula(res, num, target, i, expression + "*" + curS, newVal, preNum * curNum, op);
        }
    }
};