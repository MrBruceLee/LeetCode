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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        
        int rootVal = root->val;
        // root is in the middle of p and q
        if(p->val <= rootVal && rootVal <= q->val || q->val <= rootVal && rootVal <= p->val) {
            return root;
        }
        
        // p and q are at one side of root only;
        if(rootVal < p->val) { // right side
            return lowestCommonAncestor(root->right, p, q);
        } else { // left side
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};