// Question:
// Bigest BST in a binary tree

struct HelpNode {
    int min;
    int max;
    int size;
    bool is_bst;
    HelpNode(int min, int max, int size, bool is_bst) : min(min), max(max), size(size), is_bst(is_bst) {}
};

class Solution {
public:
    int biggestBST(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans;
    }

    HelpNode* help(TreeNode* root, int& ans) {
        if (!root) {
            return new HelpNode(INT_MAX, INT_MIN, 0, true);
        }

        auto left = help(root->left, ans);
        auto right = help(root->right, ans);

        if (!left->is_bst || !right->is_bst) {
            return new HelpNode(0, 0, 0, false);
        }
        if (root->left && left->max > root->val) {
            return new HelpNode(0, 0, 0, false);
        }
        if (root->right && right->min < root->val) {
            return new HelpNode(0, 0, 0, false);
        }

        int size = left->size + right->size + 1;
        ans = max(ans, size);
        return new HelpNode(min(left->min, root->val), max(right->max, root->val), size, true);
    }
};
