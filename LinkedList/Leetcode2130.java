package LinkedList;

import java.util.Deque;
import java.util.ArrayDeque;

public class Leetcode2130 {

    //Driver Code
    public static void main(String[] args) {
        // Create linked list: 1 -> 2 -> 3 -> 4
        ListNode head = new ListNode(4);
        head.next = new ListNode(2);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(3);

        Solution sol = new Solution();
        int result = sol.pairSum(head);

        System.out.println("Maximum Twin Sum: " + result);
    }
}

class Solution {
    public int pairSum(ListNode head) {
        
        Deque<Integer> st = new ArrayDeque<>();

        ListNode slow = head, fast = head.next;
        while(fast.next != null){
            st.push(slow.val);
            slow = slow.next;
            fast = fast.next.next;
        }

        st.push(slow.val);
        slow = slow.next;

        int maxSum = 0;
        while(!st.isEmpty() && slow != null){
            maxSum = Math.max(maxSum, st.peek() + slow.val);
            st.pop();
            slow = slow.next;
        }
        return maxSum;
    }
}


class ListNode{
    int val;
    ListNode next;
    
    ListNode(int val){
        this.val = val;
        next = null;
    }
}