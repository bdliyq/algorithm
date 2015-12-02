// Question: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        int i = 0;
        stack<TreeNode*> s;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                ++i;
                if (i == k) {
                    return node->val;
                }
                node = node->right;
            }
        }

        return -1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    cout << s.kthSmallest(root, 4) << endl;
    return 0;
}
