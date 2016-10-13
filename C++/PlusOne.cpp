class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        
        for(int i = digits.size() - 1; i >= 0; i--) {
            int num = digits[i] + carry;
            if(num > 9) {
                carry = 1;
                num = num - 10;
            } else {
                carry = 0;
            }
            
            digits[i] = num;
        }
        
        if(carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};