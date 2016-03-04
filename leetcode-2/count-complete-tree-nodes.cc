// Question: https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int hei_left = 0;
        TreeNode* node = root;
        while (node) {
            ++hei_left;
            node = node->left;
        }

        int hei_right = 0;
        node = root;
        while (node) {
            ++hei_right;
            node = node->right;
        }

        if (hei_left == hei_right) {
            return pow(2, hei_left) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
