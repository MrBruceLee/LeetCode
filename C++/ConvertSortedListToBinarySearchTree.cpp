/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        if(head->next == NULL) {
            return new TreeNode(head->val);
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* node = new TreeNode(slow->next->val);
        node->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        node->left = sortedListToBST(head);
        
        return node;
    }
};