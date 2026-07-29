#include <bits/stdc++.h>
using namespace std;

// merge two sorted list (leetcode 21)  
// Follow up -- Merge K sorted Linked List

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Dummy node to act as the start of the merged list
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;  //temp is the tail of resulting LL

    ListNode* l1 = list1;
    ListNode* l2 = list2;
 
    while(l1 && l2) {
        if (l1->val <= l2->val) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        } 
        else {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    // Append the remaining nodes from l1 or l2
    while(l1) {
        temp->next = l1;
        l1 = l1->next;
        temp = temp->next;
    }

    while(l2) {
        temp->next = l2;
        l2 = l2->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

//merge two sorted list using recursion

ListNode* mergeTwoListsRec(ListNode* h1, ListNode* h2) {
    if(h1 == NULL || h2 == NULL){
        return h1 == NULL ? h2 : h1;
    }
    if(h1->val <= h2->val){
        h1->next = mergeTwoListsRec(h1->next, h2);
        return h1;
    }else{
        h2->next = mergeTwoListsRec(h1, h2->next);
        return h2;
    }
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

// Example usage
int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};

    ListNode* l1 = createList(a);
    ListNode* l2 = createList(b);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    ListNode* merged = mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
