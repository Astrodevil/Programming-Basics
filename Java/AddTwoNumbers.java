/**
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 */

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode ans = new ListNode();
    ListNode temp = ans;
    int carry = 0;

    while (l1 != null || l2 != null || carry != 0) {
      int s = 0;
      if (l1 != null) {
        s += l1.val;
        l1 = l1.next;
      }
      if (l2 != null) {
        s += l2.val;
        l2 = l2.next;
      }

      s += carry;
      carry = s / 10;
      ListNode n = new ListNode(s % 10);
      temp.next = n;
      temp = temp.next;
    }

    return ans.next;

  }
}
