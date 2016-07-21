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
 *  Runtime - O(N)
 *  Space - O(N)
 */


class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        inorder(root);
        
        int closest = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(abs(nums[i] - target) < abs(closest - target)) {
                closest = nums[i];
            }
        }
        
        return closest;
    }
    
private:
    vector<int> nums;
    
    void inorder(TreeNode* root) {
        if(root != NULL) {
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        }
    }
};



/*
 *  Runtime - O(N)
 *  Space - O(1)
 */


class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int rootVal = root->val;
        TreeNode* nextCheck = NULL;
        
        if(rootVal > target) {
            nextCheck = root->left;
        } else {
            nextCheck = root->right;
        }
        
        if(nextCheck == NULL) {
            return rootVal;
        }
        
        int nextVal = closestValue(nextCheck, target);
        
        if(abs(nextVal - target) < abs(rootVal - target)) {
            return nextVal;
        } else {
            return rootVal;
        }
    }
};