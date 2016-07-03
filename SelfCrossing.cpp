class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        // if x.size() < 4, crossing will never happen
        for(int i = 3; i < x.size(); i++) {
            // case 1:
            if(x[i-1] <= x[i-3] && x[i] >= x[i-2]) {
                return true;
            }
            
            // case 2:
            if(i > 3 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) {
                return true;
            }
            
            // case 3:
            if(i > 4 && x[i-2] >= x[i-4] && x[i-1] <= x[i-3] && x[i-1] >= x[i-3] - x[i-5] && x[i] + x[i-4] >= x[i-2]) {
                return true;
            }
        }
        
        return false;
    }
};