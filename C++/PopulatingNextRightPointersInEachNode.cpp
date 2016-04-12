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


/*
 *  Runtime - O(n)
 *  Space - O(1)
 *  
 *  Can solve: 117. Populating Next Right Pointers in Each Node II
 *  https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
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