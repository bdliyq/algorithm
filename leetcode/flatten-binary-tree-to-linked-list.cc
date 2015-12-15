// Question: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten(root->left);
        flatten(root->right);
        TreeNode* prev = NULL;
        TreeNode* curr = root->left;
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
};
