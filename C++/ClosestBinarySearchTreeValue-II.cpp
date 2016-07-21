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
 *  Convert binary tree to a sorted vector, then solved it by two pointer
 *  Runtime - O(N)
 *  Space - O(N)
 */

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {

        inorder(root);
        
        int i;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] - target > 0) {
                break;
            }
        }
        
        int left = i - 1;
        int right = i;
        vector<int> results;
        
        while(k != 0) {
            if(left < 0) {
                results.push_back(nums[right]);
                right++;
                
            } else if (right >= nums.size()) {
                results.push_back(nums[left]);
                left--;
            } else {
                if( abs(nums[left] - target) > abs(nums[right] - target) ) {
                    results.push_back(nums[right]);
                    right++;
                } else {
                    results.push_back(nums[left]);
                    left--;
                }
            }
            k--;
        }
        
        return results;
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
 *  solve it during inorder traverse
 *  Runtime - O(N)
 *  Space - O(K)
 */

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        queue<int> q;
        inorder(root, k, target, q);
        
        vector<int> results;
        while(q.empty() == false) {
            results.push_back(q.front());
            q.pop();
        }
        
        return results;
    }
    
private:
    void inorder(TreeNode* root, int k, double target, queue<int>& q) {
        if(root != NULL) {
            inorder(root->left, k, target, q);
            
            if(q.size() < k) {
                q.push(root->val);
            } else {
                if(abs(root->val - target) < abs(q.front() - target)) {
                    q.pop();
                    q.push(root->val);
                }
            }
            
            inorder(root->right, k, target, q);
        }
    }
};