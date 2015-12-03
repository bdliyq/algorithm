// Question: https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(7);
    cout << s.maxDepth(root) << endl;
    cout << s.maxDepth(NULL) << endl;
}
