// Question: https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        auto left = invertTree(root->right);
        auto right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;
    }
};
