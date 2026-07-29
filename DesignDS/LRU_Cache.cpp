#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = tail;
    }

    int get(int key) {
        //cache miss
        if(!mp.count(key)) return -1;
    
        //cache hit
        Node* node = mp[key];
        
        deleteNode(node);
        insertAtBeginning(node);

        return node->val;
    }

    void put(int key, int val) {
        //entry already exists in map
        if(mp.count(key)) {
            Node* node = mp[key];
            node->val = val;  //shallow copy hai toh,, map me automatically updated

            deleteNode(node); 
            insertAtBeginning(node); //entry is touched --> move it to the front

            return;
        }

        //map is full... need to remove LRU
        if(mp.size() == cap) {
            Node* delNode = tail->prev;  //delete LRU

            deleteNode(delNode);
            mp.erase(key); 
        }

        Node* newNode = new Node(key, val);
        insertAtBeginning(newNode);
        mp[key] = newNode;
    }

    void deleteNode(Node* delNode) {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev->next;
    }

    void insertAtBeginning(Node* node) {
        Node* nextt =  node->next->next;

        head->next = node;
        node->prev = head;

        node->next = nextt;
        nextt->prev = node; 
    }    
};