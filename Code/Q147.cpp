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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* helper = new ListNode(0, nullptr);
        ListNode* cur = head, *pre = helper;
        
        while (cur) {
            ListNode* nxt = cur->next;
            while (pre->next && pre->next->val < cur->val) pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = helper;
            cur = nxt;
        }

        return helper->next;
    }
};