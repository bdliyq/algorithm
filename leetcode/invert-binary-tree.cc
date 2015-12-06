// Question: https://leetcode.com/problems/invert-binary-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }

        TreeNode* inv_left = invertTree(root->left);
        TreeNode* inv_right = invertTree(root->right);
        root->left = inv_right;
        root->right = inv_left;
        return root;
    }
};

void print_tree(TreeNode* root) {
    if (!root) {
        return;
    }

    cout << root->val << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    TreeNode* new_root = s.invertTree(root);
    print_tree(new_root);
}
