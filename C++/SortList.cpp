/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
 *  divide and conquer: runtime - O(N*log(N))
 */


class Solution {
    public:
    ListNode* sortList(ListNode* head) {
        // return the list, if the list only has 1 or 0 node.
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // split the list into two sub-lists
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* left = head; // left list
        ListNode* right = slow->next; // right list
        slow->next = NULL;
        
        // sorted two sub-lists separately: divide
        left = sortList(left);
        right = sortList(right);
        
        // merge two sorted sub-lists: conquer
        ListNode* dummy = new ListNode(0);
        ListNode* list = dummy;
        while(left != NULL && right != NULL) {
            if(left->val < right->val) {
                list->next = left;
                left = left->next;
            } else {
                list->next = right;
                right = right->next;
            }
            list = list->next;
        }
        if(left != NULL) {
            list->next = left;
        } else if (right != NULL) {
            list->next = right;
        }
        
        // return the merged list
        return dummy->next;
    }
    
};