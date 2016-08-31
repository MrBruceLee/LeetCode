class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        
        for(int i = 0; i < 32; i++) {
            if((a >> i & 1) == 1 && (b >> i & 1) == 1) {
                if(carry == 1) {
                    sum = sum | (1 << i);
                } else {
                    carry = 1;
                }
                
            } else if ((a >> i & 1) == 1 || (b >> i & 1) == 1) {
                if(carry == 0) {
                    sum = sum | (1 << i);
                }
                
            } else {
                if(carry == 1) {
                    sum = sum | (1 << i);
                    carry = 0;
                }
            }
        }
        
        return sum;
    }
};