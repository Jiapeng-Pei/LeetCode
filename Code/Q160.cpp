#include <stdio.h>
#include <vector>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            if (!ptrA && !ptrB) break;
            if (!ptrA) ptrA = headB;
            if (!ptrB) ptrB = headA;
        }
        
        return ptrA;
    }
};