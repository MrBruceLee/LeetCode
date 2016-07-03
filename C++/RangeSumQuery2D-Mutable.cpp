class NumMatrix {
public:
    // O(N^2)
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty() == true || matrix[0].empty() == true) {
            return;
        }
        
        r = matrix.size();
        c = matrix[0].size();
        
        row_sum.resize(r + 1, vector<int>(c + 1, 0));
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                row_sum[i][j] = row_sum[i][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    // O(N)
    void update(int row, int col, int val) {
        int diff = sumRegion(row, col, row, col) - val; // O(1)
        for(int j = col; j < c; j++) {
            row_sum[row+1][j+1] -= diff;
        }
    }
    
    // O(N)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            sum += row_sum[i+1][col2+1] - row_sum[i+1][col1];
        }
        return sum;
    }
    
private:
    vector<vector<int>> row_sum;
    int r;
    int c;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);