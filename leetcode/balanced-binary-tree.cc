// Question: https://leetcode.com/problems/balanced-binary-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (abs(max_depth(root->left) - max_depth(root->right)) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int max_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(max_depth(root->left), max_depth(root->right)) + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(10);
    cout << s.isBalanced(root) << endl;
}
