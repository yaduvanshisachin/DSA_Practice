/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int n){
        while(n > 1 && temp != NULL){
            temp = temp->next;
            n--;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        int len = 1;

        while(tail->next != NULL){
            tail = tail->next;
            len += 1;
        }
        if(k % len == 0) return head;

        k = k % len;

        tail->next = head;  // making the List circular
        ListNode* newLastNode = findNthNode(head, len - k); 

        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};