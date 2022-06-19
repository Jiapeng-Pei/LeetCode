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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* tail = head;
        while (tail->next) tail = tail->next;
        mergeSort(head, tail);
        return head;    
    }

    void mergeSort(ListNode* begin, ListNode* end) {
        if (begin == end)
            return;
        ListNode* leftEnd = findMedian(begin, end);
        mergeSort(begin, leftEnd);
        mergeSort(leftEnd->next, end);
        merge(begin, leftEnd->next, end);
    }

    void merge(ListNode* begin, ListNode* rightBegin, ListNode* end) {
        vector<int> values;
        ListNode* left = begin, *right = rightBegin;
        while (left != rightBegin && right != end->next) {
            if (left->val <= right->val) {
                values.push_back(left->val);
                left = left->next;
            }
            else {
                values.push_back(right->val);
                right = right->next;
            }
        }

        while (left != rightBegin) {
            values.push_back(left->val);
            left = left->next;
        }

        while (right != end->next) {
            values.push_back(right->val);
            right = right->next;
        }

        for (const int& i : values) {
            begin->val = i;
            begin = begin->next;
        }
    }

    ListNode* findMedian(ListNode* head, ListNode* end) {
        ListNode* endNext = end->next;
        end->next = nullptr;
        ListNode* slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        end->next = endNext;
        return slow;
    }
};