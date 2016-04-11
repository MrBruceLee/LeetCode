/*
 *  Runtime - O(n)
 *  Space - O(1)
 *
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        TreeLinkNode* tb = root;    // top to bottom ptr
        TreeLinkNode* lr = NULL;    // left to right ptr
        
        while(tb->left != NULL){
            lr = tb;
            
            while(lr != NULL){
                lr->left->next = lr->right;
                if(lr->next != NULL)
                lr->right->next = lr->next->left;
                
                lr = lr->next;
            }
            tb = tb->left;
        }
    }
};