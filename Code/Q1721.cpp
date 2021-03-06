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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* slow = head, *fast = head, *forward = head;
        for (int i = 0; i < k - 1; i++) forward = forward->next;
        for (int i = 0; i < k; i++) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val, forward->val);
        return head;        
    }
};