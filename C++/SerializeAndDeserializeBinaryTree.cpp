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

 
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL) {
                data += "null ";
            } else {
                data += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return data;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data = "null " + data; // dummy->left = NULL, dummy->right = root
        stringstream ss(data);
        
        queue<TreeNode*> q;
        TreeNode* dummy = new TreeNode(0);
        q.push(dummy);
        
        string val;
        
        while(q.empty() == false) {
            int size = q.size();
            
            while(size > 0) {
                TreeNode* root = q.front();
                q.pop();
                size--;
                
                // left value
                ss >> val;
                if(val == "null") {
                    root->left = NULL;
                } else {
                    root->left = new TreeNode(atoi(val.c_str()));
                    q.push(root->left);
                }
                
                // right value
                ss >> val;
                if(val == "null") {
                    root->right = NULL;
                } else {
                    root->right = new TreeNode(atoi(val.c_str()));
                    q.push(root->right);
                }
            }
        }
        
        return dummy->right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));