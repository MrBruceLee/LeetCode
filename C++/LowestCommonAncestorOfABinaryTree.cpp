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
 *  Divide and Conquer
 */


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root == p || root == q) {
            return root;
        }
        
        // Divide
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // Conquer
        // if one side return NULL, that means p and q may at the other side and its return value may LCA
        if(left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
            // if both sides are not return NULL, root must be LCA
        } else {
            return root;
        }
    }
};