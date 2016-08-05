/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    public:
    ListNode* partition(ListNode* head, int x) {
        // list1: nodes value are smaller than x
        // list2: nodes value are greater than or equal to x
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        
        // split
        while(head != NULL) {
            if(head->val < x) {
                ptr1->next = head;
                ptr1 = ptr1->next;
            } else {
                ptr2->next = head;
                ptr2 = ptr2->next;
            }
            head = head->next;
        }
        
        // merge
        ptr1->next = list2->next;
        ptr2->next = NULL;
        
        return list1->next;
    }
};