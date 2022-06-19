#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct myCompare {
    bool operator()(ListNode* lhs, ListNode* rhs) {
        return lhs->val > rhs->val;
    }
};
 
class Solution {
public:
    ListNode* mergeKLists_PriorityQueue(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myCompare> pq;
        for (ListNode* ptr : lists) {
            if (ptr) pq.push(ptr);
        }

        ListNode helper(0);
        ListNode* cur = &helper;
        while (pq.size()) {
            ListNode* top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next) pq.push(top->next);
        }

        return helper.next;
    }

    ListNode* mergeKLists_DivideAndConqure(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        while (lists.size() > 1) {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode helper(0);
        ListNode* cur = &helper;
        for (; l1 && l2; cur = cur->next) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } 
            else {
                cur->next = l2;
                l2 = l2->next;
            }
        }

        cur->next = l1 ? l1 : l2;

        return helper.next;
    }
};