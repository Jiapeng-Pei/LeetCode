using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode* slow = head, *fast = head, *pre = nullptr, *nxt = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;

            nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }
        ListNode* backward = pre;
        ListNode *forward = fast ? slow->next : slow;
        while (backward) {
            if (backward->val != forward->val) return false;
            backward = backward->next;
            forward = forward->next;
        }

        return true;
    }
};