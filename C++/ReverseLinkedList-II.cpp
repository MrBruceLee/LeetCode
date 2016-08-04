/*
 *  1. split into three lists
 *  2. reverse the second list
 *  3. combine into one list
 */


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        ListNode* list1end = NULL;
        ListNode* list2start = NULL;
        ListNode* list2end = NULL;
        ListNode* list3start = NULL;
        
        for(int i = 0; i <= n; i++) {
            if(i == m - 1) {
                list1end = head;
            }
            if(i == n) {
                list2end = head;
            }
            head = head->next;
        }
        
        list2start = list1end->next;
        list3start = list2end->next;
        
        list2end->next = NULL;
        list2end = list2start;
        while(list2start != NULL) {
            ListNode* tmp = list2start->next;
            list2start->next = list1end->next;
            list1end->next = list2start;
            list2start = tmp;
        }
        
        list2end->next = list3start;
        
        return dummy->next;
    }
    
};