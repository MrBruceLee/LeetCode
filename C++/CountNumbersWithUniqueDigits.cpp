class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 0;
        
        for(int i = 1; i <= n; i++) {
            int local_count = 1;
            int num = 10;
            
            for(int j = 0; j < i; j++) {
                if(j == 0) {
                    local_count = 9;
                } else {
                    local_count *= num;
                }
                num -= 1;
            }
            
            count += local_count;
        }
        
        // plus the case: [0]
        return count + 1;
    }
};