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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* list1 = head; // first list
        ListNode* list2 = slow->next; // second list
        slow->next = NULL;
        
        // sorted two sub-lists separately: divide
        list1 = sortList(list1);
        list2 = sortList(list2);
        
        // merge two sorted sub-lists: conquer
        head = &dummy;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        
        if(list1 != NULL) {
            head->next = list1;
        } else if(list2 != NULL) {
            head->next = list2;
        } else {
            head->next = NULL;
        }
        
        // return the merged list
        return dummy.next;
        
    }
};