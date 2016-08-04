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
                //delete curr;  // optional
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
        ListNode* curr = head;
        
        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                //ListNode* node = curr->next;  // optional
                curr->next = curr->next->next;
                //delete node;  // optional
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};
