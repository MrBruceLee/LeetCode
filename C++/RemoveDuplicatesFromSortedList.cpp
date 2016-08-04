/*
 *  Solution 1
 */


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            if(prev->val == curr->val) {
                prev->next = next;
                curr = next;
            }else {
                prev = curr;
                curr = next;
            }
        }
        
        return dummy->next;
    }
};




/*
 *  Solution 2: more concise
 */


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        
        while(curr->next != NULL) {
            if(curr->val == curr->next->val) {
                curr->next = curr->next->next;
                
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
    
};
