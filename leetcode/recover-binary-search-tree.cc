// Question: https://leetcode.com/problems/recover-binary-search-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root) {
            return;
        }

        TreeNode *current = NULL, *pre = NULL, *parent = NULL;
        TreeNode *f1 = NULL, *f2 = NULL;
        current = root;

        while (current) {
            if (current->left == NULL) {
                if (parent && parent->val > current->val) {
                    if (!f1) {
                        f1 = parent;
                    }
                    f2 = current;
                }
                parent = current;

                current = current->right;
            } else {
                pre = current->left;
                while (pre->right && pre->right != current) {
                    pre = pre->right;
                }

                if (pre->right == NULL) {
                    pre->right = current;
                    current = current->left;
                } else {
                    pre->right = NULL;

                    if (parent && parent->val > current->val) {
                        if (!f1) {
                            f1 = parent;
                        }
                        f2 = current;
                    }
                    parent = current;

                    current = current->right;
                }
            }
        }

        if (f1 && f2) {
            int t = f1->val;
            f1->val = f2->val;
            f2->val = t;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(4);
}
