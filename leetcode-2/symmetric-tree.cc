// Question: https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }
        if (t1 && t2) {
            return (t1->val == t2->val && helper(t1->left, t2->right) && helper(t1->right, t2->left));
        }
        return false;
    }
};
