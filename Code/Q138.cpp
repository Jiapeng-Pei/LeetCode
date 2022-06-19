#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace::std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        map<Node*, Node*> myMap;
        Node* ptr = head;
        while (ptr) {
            myMap[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            myMap[ptr]->next = myMap[ptr->next];
            if (ptr->random) myMap[ptr]->random = myMap[ptr->random];
            ptr = ptr->next;
        }

        return myMap[head];
    }
};