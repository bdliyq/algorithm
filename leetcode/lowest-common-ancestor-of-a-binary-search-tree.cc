// Question: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }

        if (p == q) {
            return p;
        }

        if (root == p || root == q) {
            return root;
        }

        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }

        if (root->val > p->val && root->val < q->val) {
            return root;
        } else if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return lowestCommonAncestor(root->right, p, q);
        }
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
    TreeNode* p = root->left;
    TreeNode* q = root->left->right;
    TreeNode* ans = s.lowestCommonAncestor(root, p, q);
    if (ans) {
        cout << ans->val << endl;
    } else {
        cout << "NULL..." << endl;
    }
}
