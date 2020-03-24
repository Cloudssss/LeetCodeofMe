/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
            if (l1==null)
            {
                return l2;
            }

            if (l2==null)
            {
                return l1;
            }

            if (l1.val+l2.val<10)
            {
                ListNode t = new ListNode(l1.val+l2.val);
                t.next = AddTwoNumbers(l1.next, l2.next);
                return t;
            }
            else
            {
                ListNode t = new ListNode(l1.val+l2.val-10);
                t.next = AddTwoNumbers(l1.next, l2.next);
                ListNode temp = new ListNode((l1.val+l2.val)/10);
                t.next = AddTwoNumbers(temp, t.next);
                return t;
            }
    }
}