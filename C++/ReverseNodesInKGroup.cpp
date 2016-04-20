/*
 *  Runtime - O(N)
 *  Space - O(N)
 *
 */


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        int cnt = 1;
        while(head->next != NULL) {
            // find a sub-list which length is k
            head = head->next;
            cnt++;
            if( cnt % k != 0) continue;
            
            // store the rest list, and set the end of the sub-list to NULL
            ListNode* next = head->next;
            head->next = NULL;
            
            // reverse the sub-list
            prev->next = reverse(prev->next);
            
            // find the new prev (which is the end of the reversed sub-list)
            while(prev->next != NULL)
                prev = prev->next;
            
            // merge reversed part with un-reversed part
            prev->next = next;
            head = prev;
        }
        
        return dummy->next;
    }
    
private:
    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        
        while(head != NULL){
            ListNode* next = head->next;
            
            ListNode* node = dummy->next;
            dummy->next = head;
            head->next = node;
            
            head = next;
        }
        
        return dummy->next;
    }
};