#include<bits/stdc++.h>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};


class Solution {
  public:
    using p = pair<int, ListNode*>;
    
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        
        priority_queue<p, vector<p>, greater<p>> pq;
        
        for(auto head : arr) {
            if(head == nullptr) continue;
            pq.push({head->val, head});
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        
        while(!pq.empty()) {
            ListNode* ListNode = pq.top().second;
            pq.pop();
            
            temp->next = ListNode;
            temp = temp->next;
        
            if(ListNode->next) {
                pq.push({ListNode->next->val, ListNode->next});
            }
        }
        
        return dummy->next;
    }   
};