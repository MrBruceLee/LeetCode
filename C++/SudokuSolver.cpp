class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // hash table - e.g. if row[i][j] equals true, it means the number 'j+1' is exsit at the (i+1)-th row.
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> squ(9, vector<bool>(9, false));
        
        // marking those exsisted numbers at the hash table
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int s = (i/3) * 3 + (j/3);
                    row[i][num] = true;
                    col[j][num] = true;
                    squ[s][num] = true;
                }
            }
        }
        
        // recursively find the answer
        dfs(board, 0, 0, row, col, squ);
    }
    
private:
    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& squ){
        // the last number was found, exit the function.
        if(i >= 9 || j >= 9){
            return true;
        }
        
        // if this place is a number, skip it and check next place
        if(board[i][j] != '.'){
            if(j >= 8 && dfs(board, i+1, 0, row, col, squ) == true ||
               j < 8 && dfs(board, i, j+1, row, col, squ) == true){
                return true;
            }else{
                return false;
            }
        }
        
        // if this place is empty, try number range from 1 to 9 and find the valid number
        int s = (i/3) * 3 + (j/3); // square number
        for(int num = 0; num < 9; num++){
            
            // inorder to guarantee this Sudoku is valid
            if(row[i][num] == false && col[j][num] == false && squ[s][num] == false){
                row[i][num] = true;
                col[j][num] = true;
                squ[s][num] = true;
                board[i][j] = num + '1';
                
                if(j >= 8 && dfs(board, i+1, 0, row, col, squ) == true ||
                   j < 8 && dfs(board, i, j+1, row, col, squ) == true){
                    return true;
                }
                
                row[i][num] = false;
                col[j][num] = false;
                squ[s][num] = false;
                board[i][j] = '.';
            }
        }
        
        // could not find a valid number
        return false;
    }
};