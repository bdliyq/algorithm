// Question: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten(root->left);
        flatten(root->right);
        TreeNode* curr = root->left;
        TreeNode* prev = NULL;
        while (curr) {
            prev = curr;
            curr = curr->right;
        }
        if (prev) {
            prev->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }

    void flatten(TreeNode* root) {
        auto node = root;
        while (node) {
            if (node->left) {
                auto prev = node->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            // node->right->left = node;
            node = node->right;
        }
    }
};
