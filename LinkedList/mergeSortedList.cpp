#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}  //constructor
};


// merge two sorted list (leetcode 21)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Dummy node to act as the start of the merged list
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;  //temp is the tail of resulting LL
 
    while (h1 != nullptr && h2 != nullptr) {
        if (l1->val < l2->val) {
            temp->next = h1;
            temp = h1;
            h1 = h1->next;
        } else {
            temp->next = h2;
            temp = h2;
            h2 = h2->next;
        }
    }
    // Append the remaining nodes from l1 or l2
    if(h1) temp->next = h1;
    else temp->next h2;

    return dummyNode->next;
}

//merge two sorted list using recursion
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

ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
    if(h1 == NULL || h2 == NULL){
        return h1 == NULL ? h2 : h1;
    }
    if(h1->val <= h2->val){
        h1->next = mergeTwoLists(h1->next, h2);
        return h1;
    }else{
        h2->next = mergeTwoLists(h1, h2->next);
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
