class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        
        while(head != NULL) {
            ListNode* next = head->next;
            
            ListNode* tmp = dummy->next;
            dummy->next = head;
            head->next = tmp;
            
            head = next;
        }
        
        return dummy->next;
    }
};