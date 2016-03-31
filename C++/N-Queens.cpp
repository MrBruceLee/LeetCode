/*
 *  Reference: https://leetcode.com/discuss/35128/accepted-solution-use-backtracking-bitmask-easy-understand
 *
 *    | | |                / / /             \ \ \
 *    O O O               O O O               O O O
 *    | | |              / / / /             \ \ \ \
 *    O O O               O O O               O O O
 *    | | |              / / / /             \ \ \ \
 *    O O O               O O O               O O O
 *    | | |              / / /                 \ \ \
 *   3 columns        5 45°diagonals       5 135°diagonals    (when n is 3)
 *
 *  When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row
 *
 */

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        
        vector<bool> flag_col(n, false);         // indicate if the column had a queen before
        vector<bool> flag_45(2 * n - 1, false);  // indicate if the 45° diagonal had a queen before.
        vector<bool> flag_135(2 * n - 1, false); // indicate if the 135° diagonal had a queen before.
        
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, vector<bool> &flag_col, vector<bool> &flag_45, vector<bool> &flag_135, int row, int n) {
        
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        
        for (int col = 0; col < n; col++)
            if (flag_col[col] == false && flag_45[row+col] == false && flag_135[n-1+col-row] == false) {
                
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = true;
                nQueens[row][col] = 'Q';
                
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row+1, n);
                
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = false;
            }
    }
};