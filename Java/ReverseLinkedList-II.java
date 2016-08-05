public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        head = dummy;
        
        // find preNode & mNode
        for(int i = 1; i < m; i++) {
            if(head == null) {
                return dummy.next;
            }
            head = head.next;
        }
        
        ListNode preNode = head;
        ListNode mNode = head.next;
        
        // reverse linked list
        ListNode nNode = mNode;
        ListNode postnNode = mNode.next;
        for(int i = m; i < n; i++) {
            ListNode tmp = postnNode.next;
            postnNode.next = nNode;
            nNode = postnNode;
            postnNode = tmp;
        }
        
        // change pointer
        mNode.next = postnNode;
        preNode.next = nNode;
        
        return dummy.next;
    }
}