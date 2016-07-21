/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
 *  level order traverse
 */


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>, less<int>> level2vector;
        unordered_map<int, int> node2level;
        vector<vector<int>> results;
        
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
            level2vector[0].push_back(root->val);
            node2level[root->val] = 0;
        }
        
        while(q.empty() == false) {
            int size = q.size();
            
            while(size > 0) {
                size--;
                TreeNode* node = q.front();
                q.pop();
                
                int nodelevel = node2level[node->val];
                
                if(node->left != NULL) {
                    level2vector[nodelevel-1].push_back(node->left->val);
                    node2level[node->left->val] = nodelevel - 1;
                    q.push(node->left);
                }
                
                if(node->right != NULL) {
                    level2vector[nodelevel+1].push_back(node->right->val);
                    node2level[node->right->val] = nodelevel + 1;
                    q.push(node->right);
                }
            }
        }
        
        for(auto e : level2vector) {
            results.push_back(e.second);
        }
        
        return results;
    }
};