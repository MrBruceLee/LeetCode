/*
 *  Runtime: O(1) per move()
 *  Space: O(N)
 */


class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = 0;
        anti_diagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int row, int col, int player) {
        int factor = (player == 1 ? 1 : -1);
        
        rows[row] += factor;
        cols[col] += factor;
        if(row == col) {
            diagonal += factor;
        }
        if(row + col == n - 1) {
            anti_diagonal += factor;
        }
        
        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(anti_diagonal) == n) {
            return player;
        } else {
            return 0;
        }
    }
    
private:
    int n;
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */





/*
 *  Runtime: O(N) per move()
 *  Space: O(N^2)
 */


class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        board.resize(n, vector<int>(n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        int cntRow = 0;
        int cntCol = 0;
        int cntDia = 0;
        int cntAnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(board[row][i] == player) {
                cntRow++;
            }
            if(board[i][col] == player) {
                cntCol++;
            }
            if(board[i][i] == player) {
                cntDia++;
            }
            if(board[i][(n-1)-i] == player) {
                cntAnt++;
            }
        }
        
        if(cntRow == n || cntCol == n || cntDia == n || cntAnt == n) {
            return player;
        } else {
            return 0;
        }
    }
    
private:
    int n;
    vector<vector<int>> board;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */