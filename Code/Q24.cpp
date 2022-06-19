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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* next = head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (next) {
            next = cur->next->next;
            ListNode* tmp = cur->next;
            tmp->next = cur;
            pre->next = tmp;
            pre = cur;
        }
    }
};