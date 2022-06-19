#include <vector>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (; head; head = head->next) nums.push_back(head->val);
        return recursive(nums, 0, nums.size() - 1);
    }

    TreeNode* recursive(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;   
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = recursive(nums, left, mid - 1);
        cur->right = recursive(nums, mid + 1, right);
        return cur;
    }

    // TreeNode* recursive(ListNode* head, ListNode* tail) {
    //     // [head, tail) denotes the LinkdedList.
    //     if (head == tail) return nullptr;
    //     if (head->next == tail) return new TreeNode(head->val);
    //     ListNode *slow = head, *fast = head;
    //     while (fast != tail && fast->next != tail) {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     TreeNode* cur = new TreeNode(slow->val);
    //     cur->left = recursive(head, slow);
    //     cur->right = recursive(slow->next, tail);
        
    //     return cur;
    // }
};