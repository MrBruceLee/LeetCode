class Solution {
public:
    int numberOfPatterns(int m, int n) {
        used.resize(10, 0);
        int res = 0;
        
        for(int i = m; i <= n; i++) {
            res += calculatePath(0, i);
        }
        
        return res;
    }
    
private:
    vector<bool> used;
    
    int calculatePath(int prevDigit, int len) {
        if(len == 0) {
            return 1;
        }
        
        int sum = 0;
        for(int i = 1; i <= 9; i++) {
            if(isValid(prevDigit, i) == true) {
                used[i] = true;
                sum += calculatePath(i, len - 1);
                used[i] = false;
            }
        }
        
        return sum;
    }
    
    bool isValid(int prevDigit, int currDigit) {
        // the first digit
        if(prevDigit == 0) {
            return true;
        }
        
        // this number is used
        if(used[currDigit] == true) {
            return false;
        }
        
        // adjacent & knight moves
        if((prevDigit + currDigit) % 2 == 1) {
            return true;
        }
        
        int mid = (prevDigit + currDigit) / 2;
        // cross 5
        if(mid == 5) {
            return used[mid];
        }
        
        // short diagonal
        if(prevDigit % 3 != currDigit % 3 && (prevDigit-1) / 3 != (currDigit-1) / 3) {
            return true;
        }
        
        // others that not adjacent
        return used[mid];
    }
    
};