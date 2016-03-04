// Question: https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) {
            return ans;
        }

        stack<pair<TreeNode*, string>> s;
        s.push(make_pair(root, ""));
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            auto node = p.first;
            auto path = p.second;
            stringstream ss;
            if (!path.empty()) {
                ss << "->";
            }
            ss << p.first->val;

            path += ss.str();
            if (node->left) {
                s.push(make_pair(node->left, path));
            }
            if (node->right) {
                s.push(make_pair(node->right, path));
            }
            if (!node->left && !node->right) {
                ans.push_back(path);
            }
        }
    }
};
