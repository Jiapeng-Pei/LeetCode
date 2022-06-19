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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        ListNode* evenHead = head->next;
        ListNode* prepreNode = head, *preNode = head->next, *cur = head->next->next;
        int curIndex = 2;
        while (cur) {
            curIndex++;
            prepreNode->next = cur;
            prepreNode = preNode;
            preNode = cur;
            cur = cur->next;
        }

        if (curIndex % 2 == 0) {
            prepreNode->next = evenHead;
        }
        else {
            preNode->next = evenHead;
            prepreNode->next = nullptr;
        }

        return head;
    }
};