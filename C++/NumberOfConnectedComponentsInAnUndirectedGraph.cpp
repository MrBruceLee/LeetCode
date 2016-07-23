/*
 *  BFS - Breadth First Search
 *  nodes[i] = 0: unknown
 *  nodes[i] = 1: visited/checked
 */


class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> DirectEdges;
        vector<int> nodes(n, 0);
        
        for(auto e : edges) {
            DirectEdges[e.first].push_back(e.second);
            DirectEdges[e.second].push_back(e.first);
        }
        
        int numGraphs = 0;
        
        for(int i = 0; i < n; i++) {
            if(nodes[i] != 0) {
                continue;
            }
            
            numGraphs++;
            
            queue<int> q;
            q.push(i);
            while(q.empty() == false) {
                int node = q.front();
                q.pop();
                nodes[node] = 1;
                
                for(int child : DirectEdges[node]) {
                    if(nodes[child] == 0) {
                        nodes[child] = 1;
                        q.push(child);
                        
                    }
                }
            }
        }
        
        return numGraphs;
    }
};