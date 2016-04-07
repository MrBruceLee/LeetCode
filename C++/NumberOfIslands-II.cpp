/*
 *  https://leetcode.com/discuss/69572/easiest-java-solution-with-explanations
 *  Change to C++ code, based on this JAVA solution. (see details)
 *
 */

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> islands;
        if(positions.empty()) return islands;
        
        vector<pair<int, int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        vector<int> roots(n*m, -1);                           // one root per island
        int numIsland = 0;
        
        for(auto position : positions){
            int root = position.first * n + position.second;  // ID of the position, ID = x * n + y
            roots[root] = root;                               // assume new position is an island
            numIsland++;
            
            for(auto direction : directions){
                int x = position.first + direction.first;
                int y = position.second + direction.second;
                int nei = x * n + y;                          // ID of the position's neighbor
                
                if( x < 0 || x >= m || y < 0 || y >= n || roots[nei] == -1)
                    continue;
                
                int neiRoot = findRoot(roots, nei);           // trace neighbor's root
                
                if(neiRoot != root){                          // neighbor is another island
                    roots[root] = nei;                        // union two island
                    root = neiRoot;                           // update root
                    numIsland--;
                }
            }
            
            islands.push_back(numIsland);
        }
        
        return islands;
    }
    
private:
    int findRoot(vector<int>& roots, int id){
        while(roots[id] != id) {
            //roots[id] = roots[roots[id]];                     // path compression
            id = roots[id];
        }
        return id;
    }
};