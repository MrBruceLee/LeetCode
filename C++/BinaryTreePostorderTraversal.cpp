/*
 *  pre-order traversal      root-left-right
 *  post-order traversal     left-right-root
 *
 *  modify traverse order as root-right-left, and store those value in a reverse order.
 *
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        stack<TreeNode*> s;
        
        sNode.push(root);
        
        while(!sNode.empty()){
            TreeNode* node = sNode.top();
            sNode.pop();
            
            // insert val in at the front, instead of push it at the back
            res.insert(res.begin(), node->val);
            
            // preorder traversal: push right then left
            // now: push left then right
            if(node->left) sNode.push(node->left);
            if(node->right) sNode.push(node->right);
        }
        
        return res;
    }
};