// Question: https://leetcode.com/problems/binary-tree-paths/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) {
            return ans;
        }

        queue<pair<TreeNode*, string>> q;
        q.push(make_pair(root, ""));
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            string path = q.front().second;
            q.pop();
            stringstream ss;
            if (!path.empty()) {
                ss << "->";
            }
            ss << node->val;
            path += ss.str();

            if (node->left) {
                q.push(make_pair(node->left, path));
            }
            if (node->right) {
                q.push(make_pair(node->right, path));
            }
            if (!node->left && !node->right) {
                ans.push_back(path);
            }
        }

        return ans;
    }
};
