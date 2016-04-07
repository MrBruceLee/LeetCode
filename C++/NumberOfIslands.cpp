/*
 *  DFS
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        row = grid.size();
        col = grid[0].size();
        
        int numIsland = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    // if there is '1', it must be apart of a island
                    // then mark the whole island to '2' by DFS
                    markIsland(grid, i, j);
                    numIsland++;
                }
            }
        }
        
        return numIsland;
    }
    
private:
    int row;
    int col;
    
    void markIsland(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= row || j < 0 || j >= col) return;
        if(grid[i][j] != '1') return;
        
        grid[i][j] = '2';
        
        markIsland(grid, i+1, j);
        markIsland(grid, i-1, j);
        markIsland(grid, i, j+1);
        markIsland(grid, i, j-1);
    }
};