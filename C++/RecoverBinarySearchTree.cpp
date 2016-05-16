/*
 *  Since the problem require O(1) space, we coudl not use recursion (which is O(N) space) to solve it.
 *  Morris Traversal can achieve O(1) space.
 *  https://leetcode.com/discuss/26310/detail-explain-about-morris-traversal-finds-incorrect-pointer
 *
 */


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
    void recoverTree(TreeNode* root) {
        // Morris Traversal
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        
        // Recover Binary Search Tree
        TreeNode* prevNode = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        
        while(curr != NULL){
            
            if(curr->left != NULL){
                // find predecessor
                prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }
                
                //
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                    
                }else{
                    // print "curr->val"
                    if(prevNode != NULL && prev->val > curr->val){
                        if(first == NULL){
                            first = prevNode;
                            second = curr;
                        }else{
                            second = curr;
                        }
                    }
                    prevNode = curr;
                    
                    prev->right = NULL;
                    curr = curr->right;
                    
                }
                
            }else{
                // print "curr->val"
                if(prevNode != NULL && prevNode->val > curr->val){
                    if(first == NULL){
                        first = prevNode;
                        second = curr;
                    }else{
                        second = curr;
                    }
                }
                prevNode = curr;
                
                curr = curr->right;
            }
        }
        
        // swap two misorder nodes
        if(first != NULL && second != NULL){
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};