public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode rList = null;
        
        while(head != null) {
            ListNode tmp = head.next;
            
            head.next = rList;
            rList = head;
            head = tmp;
        }
        
        return rList;
    }
}