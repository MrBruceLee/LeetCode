/*
 *  DFS - Deep First Search
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0 || board.empty() == true || board[0].empty() == true) {
            return false;
        }
        
        row = board.size();
        col = board[0].size();
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(trackWord(i, j, 0, board, word) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    int row;
    int col;
    
    bool trackWord(int i, int j, int pos, vector<vector<char>>& board, string& word) {
        if(pos == word.size() ) {
            return true;
        }
        if(i < 0 || i >= row || j < 0 || j >= col) {
            return false;
        }
        
        if(board[i][j] == word[pos]) {
            // The same letter cell may not be used more than once
            board[i][j] = '/0';
            
            if (trackWord(i+1, j, pos+1, board, word) || trackWord(i-1, j, pos+1, board, word) || trackWord(i, j+1, pos+1, board, word) || trackWord(i, j-1, pos+1, board, word)) {
                return true;
            }
            
            board[i][j] = word[pos];
        }
        
        return false;
    }
};