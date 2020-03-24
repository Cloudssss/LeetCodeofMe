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
        ListNode root = new ListNode(0);
            ListNode cursor = root;
            int carry = 0;
            while (l1!=null||l2!=null||carry!=0)
            {
                int a = l1 == null ? 0 : l1.val;
                int b = l2 == null ? 0 : l2.val;
                int c = a + b + carry;
                if (c>=10)
                {
                    carry = 1;
                    c -= 10;
                }
                else
                {
                    carry = 0;
                }
                cursor.next=new ListNode(c);
                if(l1!=null) l1 = l1.next;
                if(l2!=null) l2 = l2.next;
                cursor = cursor.next;
            }

            return root.next;
    }
}