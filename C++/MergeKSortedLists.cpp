/*
 *  Heap
 */

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue constructor
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // K * log(K)
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        // N * K * log(K)
        while(pq.empty() == false) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next != NULL) {
                pq.push(tail->next);
            }
        }
        
        return dummy->next;
    }
    
private:
    // priority_queue is max heap by default. Here we need define it as a min heap
    struct compare {
        bool operator()(ListNode* v1, ListNode* v2) {
            return v1->val > v2->val;
        }
    };
};