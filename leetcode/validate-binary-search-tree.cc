// Question: https://leetcode.com/problems/validate-binary-search-tree/

#include "headers.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }

private:
    bool helper(TreeNode* root, long max_val, long min_val) {
        if (!root) {
            return true;
        }

        if ((long)root->val >= max_val || (long)root->val <= min_val) {
            return false;
        }

        return helper(root->left, root->val, min_val) && helper(root->right, max_val, root->val);
    }
};


int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(16);
    Solution s;
    cout << s.isValidBST(root);
}
