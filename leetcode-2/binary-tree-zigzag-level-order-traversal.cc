// Question: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        int curr = 1;
        int next = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            --curr;
            if (node->left) {
                ++next;
                q.push(node->left);
            }
            if (node->right) {
                ++next;
                q.push(node->right);
            }
            if (curr == 0) {
                swap(curr, next);
                if (ans.size() % 2 != 0) {
                    reverse(level.begin(), level.end());
                }
                ans.push_back(level);
                level.clear();
            }
        }
        return ans;
    }
};
