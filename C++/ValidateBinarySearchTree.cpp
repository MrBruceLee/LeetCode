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
    bool isValidBST(TreeNode* root) {
        inorderTraverse(root);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    vector<int> nums;
    
    void inorderTraverse(TreeNode* root) {
        if(root != NULL) {
            inorderTraverse(root->left);
            nums.push_back(root->val);
            inorderTraverse(root->right);
        }
    }
};





/*
 *  Runtime - O(N)
 *  Space - O(1)
 */


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        if(isValidBST(root->left) == false) {
            return false;
        }
        
        if(preVal >= root->val) {
            return false;
        }
        preVal = root->val;
        
        if(isValidBST(root->right) == false) {
            return false;
        }
        
        return true;
    }
    
private:
    long long preVal = LONG_MIN; // prevent first node value eqauls INT_MIN
};





/*
 *  Runtime - O(N)
 *  Space - O(1)
 */


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        
        if(isValidBST(root->left) == false) {
            return false;
        }
        
        if(isFirstNode == false && preVal >= root->val) {
            return false;
        }
        isFirstNode = false;
        preVal = root->val;
        
        if(isValidBST(root->right) == false) {
            return false;
        }
        
        return true;
    }
    
private:
    int preVal = INT_MIN;
    bool isFirstNode = true; // prevent first node value eqauls INT_MIN
};