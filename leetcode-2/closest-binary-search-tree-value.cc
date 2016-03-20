// Question:
// Closest Binary Search Tree Value
// Total Accepted: 1815 Total Submissions: 6418 Difficulty: Easy
// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
// Note:
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.

class Solution {
public:
    int closestValue(TreeNode* root, int value) {
        if (!root) {
            return 0;
        }

        auto node = root;
        int ans = 0;
        int min_diff = INT_MAX;
        while (node) {
            int diff = abs(root->val - value);
            if (diff < min_diff) {
                min_diff = diff;
                ans = root->val;
            }

            if (node->val < value) {
                node = node->right;
            } else if (node->val > value) {
                node = node->left;
            } else {
                return node->val;
            }
        }
        return ans;
    }
};
