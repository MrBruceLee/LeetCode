/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp; // map: oldNode --> newNode
        queue<UndirectedGraphNode*> q; // BFS
        
        // copy nodes
        q.push(node);
        while(q.empty() == false) {
            UndirectedGraphNode* oldNode = q.front();
            q.pop();
            
            UndirectedGraphNode* newNode = new UndirectedGraphNode(oldNode->label);
            mp[oldNode] = newNode;
            
            for(int i = 0; i < (oldNode->neighbors).size(); i++) {
                if(mp.find((oldNode->neighbors)[i]) == mp.end()) {
                    q.push((oldNode->neighbors)[i]);
                }
            }
        }
        
        // copy links
        for(auto e : mp) {
            for(int i = 0; i < ((e.first)->neighbors).size(); i++) {
                (e.second->neighbors).push_back( mp[ ((e.first)->neighbors)[i] ] );
            }
        }
        
        return mp[node];
    }
};