// Question: https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (!root) {
            return ans;
        }
        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 0));
        while (!s.empty()) {
            auto e = s.top();
            s.pop();
            auto node = e.first;
            auto path = e.second;
            if (!node->left && !node->right) {
                ans += path*10+node->val;
            } else {
                if (node->left) {
                    s.push(make_pair(node->left, path*10+node->val));
                }
                if (node->right) {
                    s.push(make_pair(node->right, path*10+node->val));
                }
            }
        }
        return ans;
    }
};
