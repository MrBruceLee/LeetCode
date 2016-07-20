/*
 *  each node has three state:
 *  0: unknown
 *  1: visited
 *  2: checked
 */


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        
        unordered_map<int, vector<int>> n2n;
        vector<int> nodes(n, 0);
        
        for(auto e : edges) {
            n2n[e.first].push_back(e.second);
            n2n[e.second].push_back(e.first);
        }
        
        queue<int> q;
        q.push(0);
        while(q.empty() == false) {
            int theNode = q.front();
            q.pop();
            nodes[theNode] = 2;
            
            for(int e : n2n[theNode]) {
                // if its child node is "unknown", mark it as "visited"
                if(nodes[e] == 0) {
                    nodes[e] = 1;
                    q.push(e);
                // if its child node is "visited", return false
                } else if (nodes[e] == 1) {
                    return false;
                }
                // if its child node is "checked", skip it and do nothing
            }
        }
        
        for(int i = 0; i < nodes.size(); i++) {
            if(nodes[i] == 0) {
                return false;
            }
        }
        
        return true;
    }
};