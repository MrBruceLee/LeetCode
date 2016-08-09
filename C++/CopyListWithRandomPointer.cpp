/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */



/*
 *  Runtime - O(N)
 *  Space - O(N)
 */


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // map: old list node -> new list node
        unordered_map<RandomListNode*, RandomListNode*> mp;
        
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* newList = dummy;
        RandomListNode* oldList = head;
        // copy next
        while(oldList != NULL) {
            RandomListNode* node = new RandomListNode(oldList->label);
            newList->next = node;
            mp[oldList] = node;
            
            newList = newList->next;
            oldList = oldList->next;
        }
        
        newList = dummy->next;
        oldList = head;
        // copy random
        while(oldList != NULL) {
            newList->random = mp[oldList->random];
            
            newList = newList->next;
            oldList = oldList->next;
        }
        
        return dummy->next;
    }
};




/*
 *  Runtime - O(N)
 *  Space - O(1)
 */


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // copy next
        RandomListNode* ptr = head;
        while(ptr != NULL) {
            RandomListNode* node = new RandomListNode(ptr->label);
            
            RandomListNode* tmp = ptr->next;
            ptr->next = node;
            node->next = tmp;
            
            ptr = ptr->next->next;
        }
        
        // copy random
        ptr = head;
        while(ptr != NULL) {
            if(ptr->random != NULL) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        
        // split list
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* newList = dummy;
        ptr = head;
        while(ptr != NULL) {
            RandomListNode* tmp = ptr->next->next;
            newList->next = ptr->next;
            newList = newList->next;
            
            ptr->next = tmp;
            ptr = tmp;
            
        }
        
        return dummy->next;
    }
};