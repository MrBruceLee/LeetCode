class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() == true || grid[0].empty() == true) {
            return 0;
        }
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> kills(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++) {
            int enemy = 0;
            int begin = 0;
            for(int j = 0; j <= c; j++) {
                if(j < c && grid[i][j] == 'E') {
                    enemy++;
                }
                if (j == c || grid[i][j] == 'W') {
                    for(int k = begin; k < j; k++) {
                        kills[i][k] += enemy;
                    }
                    begin = j + 1;
                    enemy = 0;
                }
            }
        }
        
        for(int j = 0; j < c; j++) {
            int enemy = 0;
            int begin = 0;
            for(int i = 0; i <= r; i++) {
                if(i < r && grid[i][j] == 'E') {
                    enemy++;
                }
                if (i == r || grid[i][j] == 'W') {
                    for(int k = begin; k < i; k++) {
                        kills[k][j] += enemy;
                    }
                    begin = i + 1;
                    enemy = 0;
                }
            }
        }
        
        int maxEnemy = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == '0') {
                    maxEnemy = max(maxEnemy, kills[i][j]);
                }
            }
        }
        
        return maxEnemy;
    }
};