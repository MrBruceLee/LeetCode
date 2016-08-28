/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> results;
        findLeavesHelper(root, results);
        return results;
    }
    
private:
    int findLeavesHelper(TreeNode* root, vector<vector<int>>& results) {
        if(root == NULL) {
            return 0;
        }
        
        int l_height = findLeavesHelper(root->left, results);
        int r_height = findLeavesHelper(root->right, results);
        
        int height = max(l_height, r_height) + 1;
        if(results.size() < height) {
            results.push_back(vector<int>());
        }
        results[height-1].push_back(root->val);
        
        return height;
    }
};