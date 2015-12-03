// Question: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }

        if (!head->next) {
            return new TreeNode(head->val);
        }

        ListNode* left;
        ListNode* right;
        split(head, left, right);
        TreeNode* root = new TreeNode(right->val);
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right->next);
        return root;
    }

private:
    void split(ListNode* head, ListNode*& left, ListNode*& right) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        left = head;
        right = slow->next;
        slow->next = NULL;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        ListNode* head = new ListNode(1);
        TreeNode* root = s.sortedListToBST(head);
        cout << root->val << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        TreeNode* root = s.sortedListToBST(head);
        cout << root->val << " " << root->left->val << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        TreeNode* root = s.sortedListToBST(head);
        cout << root->val << " " << root->left->val << " " << root->right->val << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        TreeNode* root = s.sortedListToBST(head);
        cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->left->left->val << endl;
    }
}
