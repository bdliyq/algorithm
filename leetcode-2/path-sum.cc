// Question: https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return sum == 0;
        }
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, sum));
        while (!s.empty()) {
            auto e = s.top();
            s.pop();
            auto node = e.first;
            auto left = e.second;
            if (left - node->val == 0 && !node->left && !node->right) {
                return true;
            }
            if (node->left) {
                s.push(make_pair(node->left, left-node->val));
            }
            if (node->right) {
                s.push(make_pair(node->right, left-node->val));
            }
        }
        return false;
    }
};
