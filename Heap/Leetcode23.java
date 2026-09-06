// Definition for singly-linked list.
import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        
        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.val, b.val)
        );
        
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;

        for(ListNode list : lists){
            if(list != null){
                pq.offer(list);
            }
        }

        while(!pq.isEmpty()){
            ListNode node = pq.peek();
            pq.poll();

            temp.next = node;
            temp = temp.next;

            if(node.next != null){
                pq.offer(node.next);
            }

        }

        return dummy.next;
    }
}

public class Leetcode23 {
    public static void main(String[] args) {
        
    }
}


//TC -- >  O(k log k + n log k)