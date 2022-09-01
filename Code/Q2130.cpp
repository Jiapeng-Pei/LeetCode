#include "DataStructures.cpp"

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        int ret = 0;
        ListNode* tail = reverseLinkedList(slow);
        while (tail) {
            ret = max(ret, head->val + tail->val);
            head = head->next;
            tail = tail->next;
        }
        
        return ret;
    }
    
    ListNode* reverseLinkedList(ListNode* head) {
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