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
        ListNode* pre = nullptr;
        while (head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
            return head;
        ListNode dummyNode(0, head);
        ListNode* pre = &dummyNode;
        while (head) {
            ListNode* tail = head;
            int i = 1;
            while (i < k && tail && tail->next) {
                tail = tail->next;
                i++;
            }
            
            if (i == k) {
                ListNode* nextNode = tail->next;
                tail->next = nullptr;
                pre->next = reverseList(head);
                head->next = nextNode;
                pre = head;
                head = head->next;
            }
            else {
                head = tail->next;                
            }
        }    

        return dummyNode.next;    
    }
};