class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> money = robHelper(root);
        return max(money[0], money[1]);
    }
    
private:
    vector<int> robHelper(TreeNode* root) {
        vector<int> money(2, 0);
        
        if(root == NULL) {
            return money;
        }
        
        vector<int> left = robHelper(root->left);
        vector<int> right = robHelper(root->right);
        
        // if the root can be robbed
        money[0] = max(left[0] + right[0], left[1] + right[1] + root->val);
        // if the root can NOT be robbed
        money[1] = left[0] + right[0];
        
        return money;
    }
};