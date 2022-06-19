#include <stdio.h>
#include <vector>
#include <algorithm>  
#include <iostream>

using namespace::std;

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* cur = head;
        while (cur) {
            nextNode = cur->next;
            cur->next = prevNode;
            prevNode = cur;
            cur = nextNode;
        }
        return prevNode;
    }
};
