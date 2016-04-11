/*
 *  Runtime - O(N)
 *  Space - O(1)
 *
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        TreeLinkNode* tb = root;    // top to bottom pointer
        TreeLinkNode* lr = NULL;    // left ro right pointer
        
        // iterating from top layer to bottom layer
        while(tb != NULL){
            lr = tb;
            
            TreeLinkNode* dummy = new TreeLinkNode(0); // to avoid segmentation fault
            TreeLinkNode* curr = dummy;
            
            // iterating current layer from left to right
            while(lr != NULL){
                if(lr->left != NULL){
                    curr->next = lr->left;
                    curr = curr->next;
                }
                if(lr->right != NULL){
                    curr->next = lr->right;
                    curr = curr->next;
                }
                lr = lr->next;
            }
            
            tb = dummy->next;
            delete dummy; // garbage collection, to achieve constant space
        }
    }
};