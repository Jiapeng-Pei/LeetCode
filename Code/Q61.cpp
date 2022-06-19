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
    ListNode* rotateRight(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr || n <= 0)
            return head;
        ListNode* slow = head;
        int size = 1;
        while (slow->next) {
            slow = slow->next;
            size++;
        }

        n = n % size;
        if (!n) return head;

        slow->next = head;
        slow = head;
        int i = 1;
        while (i < size - n) {
            slow = slow->next;
            i++;
        }
        ListNode* ret = slow->next;
        slow->next = nullptr;

        return ret;
    }
};