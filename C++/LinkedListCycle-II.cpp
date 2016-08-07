class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow) {
                slow = head;
                while(slow != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};