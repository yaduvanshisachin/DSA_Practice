class Solution {
public:
    int getSize(ListNode* head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
    }    return size;
    
    ListNode* middleNode(ListNode* head) {
        for(int i = 0; i<getSize(head)/2; i++) {
            head = head->next;
        }
        return head;
};

//slow fast pointer approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
