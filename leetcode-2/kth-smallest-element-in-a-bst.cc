// Question: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        while (true) {
            int left = count_nodes(root->left);
            if (left + 1 == k) {
                return root->val;
            } else if (left + 1 > k) {
                return kthSmallest(root->left, k);
            } else {
                return kthSmallest(root->right, k - left - 1);
            }
        }
    }

    int count_nodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return count_nodes(root->left) + count_nodes(root->right) + 1;
    }
};
