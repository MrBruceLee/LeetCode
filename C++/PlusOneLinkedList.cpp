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
    ListNode* plusOne(ListNode* head) {
        head = reverseLinkedList(head);
        
        ListNode* ptr = head;
        bool carry = true;
        while(ptr != NULL) {
            if(carry == false) {
                break;
            }
            if(ptr->val == 9) {
                ptr->val = 0;
                carry = true;
            } else {
                ptr->val += 1;
                carry = false;
            }
            ptr = ptr->next;
        }
        
        head = reverseLinkedList(head);
        
        if(carry == true) {
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }
        
        return head;
    }
    
private:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        
        while(head != NULL) {
            ListNode* node = head;
            head = head->next;
            
            node->next = dummy->next;
            dummy->next = node;
        }
        
        return dummy->next;
    }
};