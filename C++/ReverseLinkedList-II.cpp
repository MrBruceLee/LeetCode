class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        ListNode* list1end = NULL;
        ListNode* list2end = NULL;
        while(n >= 0) {
            if(m == 1) {
                list1end = head;
            }
            if(n == 0) {
                list2end = head;
            }
            head = head->next;
            m--;
            n--;
        }
        
        ListNode* list2start = list1end->next;
        ListNode* list3start = list2end->next;
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