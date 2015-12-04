// Question: https://leetcode.com/problems/path-sum/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }

        int left = sum-root->val;
        if (left == 0 && !root->left && !root->right) {
            return true;
        }
        return hasPathSum(root->left, left) || hasPathSum(root->right, left);
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(-2);
    root->left = new TreeNode(-3);
    cout << s.hasPathSum(root, -5) << endl;
}
