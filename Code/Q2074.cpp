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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        for (int len = 1; len < 1e6 && head; len++) {
            ListNode* tail = head;

            // get enough number of nodes, or stop at the end of the linkedlist
            int j = 1;
            while (j < len && tail && tail->next) {
                tail = tail->next;
                j++;
            }

            if (j % 2 == 0) {
                ListNode* nextHead = tail->next;
                tail->next = nullptr;
                prev->next = reverseList(head);
                prev = head;
                head->next = nextHead;
                head = head->next;
            } 
            else {
                prev = tail;
                head = tail->next;
            }    
        }

        return dummy->next;
    }
};