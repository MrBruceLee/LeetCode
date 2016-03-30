/*  
 *  Manhattan Distance
 *  https://en.wikipedia.org/wiki/Taxicab_geometry
 *  Manhattan distance allows us to calculate x and y seperately.
 *
 *  Geometric Median
 *  https://en.wikipedia.org/wiki/Geometric_median
 *  The geometric median is the point minimizing the sum of distances to the sample points.
 */

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> x;
        vector<int> y;
        
        // recording each p.x and p.y
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        
        int sum = 0; // the total travel distance
        
        // since p.x is recoreded by order, we do not need sort vector x
        int midX = x[x.size()/2];
        for(int xx : x)
            sum += abs(xx - midX);
        
        // only vector y need to be sorted
        sort(y.begin(), y.end());
        int midY = y[y.size()/2];
        for(int yy : y)
            sum += abs(yy - midY);
        
        return sum;
    }
    
};