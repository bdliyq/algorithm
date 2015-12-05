// Question: https://leetcode.com/problems/count-complete-tree-nodes/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        TreeNode* left = root;
        int left_hei = 0;
        while (left) {
            left = left->left;
            ++left_hei;
        }

        TreeNode* right = root;
        int right_hei = 0;
        while (right) {
            right = right->right;
            ++right_hei;
        }

        if (left_hei == right_hei) {
            return pow(2, left_hei) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    cout << s.countNodes(root) << endl;
}
