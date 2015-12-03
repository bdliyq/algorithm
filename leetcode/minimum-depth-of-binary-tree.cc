// Question: https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return helper(root);
    }

private:
    int helper(TreeNode* root) {
        if (!root) {
            return INT_MAX;
        }

        int left = helper(root->left);
        int right = helper(root->right);
        if (left == INT_MAX && right == INT_MAX) {
            return 1;
        }
        return min(left, right) + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    cout << s.minDepth(root) << endl;
    cout << s.minDepth(NULL) << endl;
    return 0;
}
