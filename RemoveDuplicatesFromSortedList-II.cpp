class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            
            while(next != NULL && curr->val == next->val) {
                next = next->next;
            }
            
            if(curr->next == next) {
                prev->next = curr;
                prev = curr;
            } else {
                prev->next = next;
            }
            
            curr = next;
        }
        
        return dummy->next;
    }
};