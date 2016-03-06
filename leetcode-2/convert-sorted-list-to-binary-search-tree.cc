// Question: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode* left, *right;
        split_list(head, left, right);
        auto root = new TreeNode(right->val);
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right->next);
        return root;
    }

    void split_list(ListNode* head, ListNode*& h1, ListNode*& h2) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        h1 = head;
        h2 = slow->next;
        slow->next = NULL;
    }
};


