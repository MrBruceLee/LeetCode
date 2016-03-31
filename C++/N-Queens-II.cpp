/*
 *  The same idea with N-Queens
 */
 

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> flag_col(n, false);
        vector<bool> flag_45(2*n-1, false);
        vector<bool> flag_135(2*n-1, false);
        
        int cnt = 0;
        dfsQueens(cnt, 0, n, flag_col, flag_45, flag_135);
        return cnt;
    }
    
private:
    void dfsQueens(int& cnt, int row, int n, vector<bool>& flag_col, vector<bool>& flag_45, vector<bool>& flag_135){
        if(row == n){
            cnt++;
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(flag_col[col] == false && flag_45[col+row] == false && flag_135[n-1+col-row] == false){
                
                flag_col[col] = flag_45[col+row] = flag_135[n-1+col-row] = true;
                dfsQueens(cnt, row+1, n, flag_col, flag_45, flag_135);
                flag_col[col] = flag_45[col+row] = flag_135[n-1+col-row] = false;
            }
        }
    }
    
};