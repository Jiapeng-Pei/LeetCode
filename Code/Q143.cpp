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
    void reorderList(ListNode* head) {
        // 1. find the median of ListedList.
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* l2 = reverseList(slow->next);
        ListNode* l1 = head;
        slow->next = nullptr;
        ListNode* cur = new ListNode(0, head);
        while (l1 || l2) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
            if (l2) {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *nxt = nullptr;
        while (head) {
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        
        return pre;
    }
};