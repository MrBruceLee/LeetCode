class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        
        // health[i][j] represents the min health the knight need at position (i, j)
        vector<vector<int>> health(row + 1, vector<int>(col + 1, INT_MAX));
        
        // If at any point his health point drops to 0 or below, he dies immediately
        health[row][col-1] = 1;
        health[row-1][col] = 1;
        
        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                // to calculate how much extra health need at point (i, j)
                int need = min(health[i+1][j], health[i][j+1]) - dungeon[i][j];
                
                // if no extra health required, the knight only need 1 health to keep his life
                if(need <= 0) {
                    health[i][j] = 1;
                } else {
                    health[i][j] = need;
                }
            }
        }
        
        return health[0][0];
    }
};