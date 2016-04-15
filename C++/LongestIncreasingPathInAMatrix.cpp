/*
 *  Depth-First Search - DFS
 *  Memorization
 *
 *  The key of this problem is to "cache" the distance
 *
 */


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        row = matrix.size();
        col = matrix[0].size();
        
        vector<vector<int>> cache(row, vector<int>(col, 0));
        
        int maxHops = 1;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                maxHops = max(maxHops, findMaxPath(i, j, matrix, cache));
        
        return maxHops;
    }
    
private:
    int row;
    int col;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int findMaxPath(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& cache){
        // if the location is visited, then return its distance from cache
        if(cache[i][j] != 0) return cache[i][j];
        
        int hop = 1; // max hops among four directions, at least 1
        
        for(auto direction : directions){
            int x = i + direction[0];
            int y = j + direction[1];
            
            if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] <= matrix[i][j])
                continue;
            
            hop = max(hop, findMaxPath(x, y, matrix, cache) + 1);
        }
        
        cache[i][j] = hop; // cache it
        return hop;
    }
};