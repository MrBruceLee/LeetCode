class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // e.g. row[i][j]: whether the number "j+1" appeared at the i-th row.
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> squ(9, vector<bool>(9, false));
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // skip all '.'
                if(board[i][j] == '.'){
                    continue;
                }
                
                int number = (int)board[i][j] - '1';
                
                if(row[i][number] == true){
                    return false;
                }
                row[i][number] = true;
                
                if(col[j][number] == true){
                    return false;
                }
                col[j][number] = true;
                
                int square = (i/3) * 3 + (j/3);
                if(squ[square][number] == true){
                    return false;
                }
                squ[square][number] = true;
            }
        }
        
        return true;
    }
};