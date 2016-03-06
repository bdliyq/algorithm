// Question: https://leetcode.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 */
#include "headers.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        stack<tuple<TreeNode*, vector<int>, int>> s;
        s.push(make_tuple(root, vector<int>(), sum));
        while (!s.empty()) {
            auto e = s.top();
            s.pop();
            TreeNode* node;
            vector<int> path;
            int left;
            tie(node, path, left) = e;
            path.push_back(node->val);
            if (left - node->val == 0 && !node->left && !node->right) {
                ans.push_back(path);
            }
            if (node->left) {
                s.push(make_tuple(node->left, path, left-node->val));
            }
            if (node->right) {
                s.push(make_tuple(node->right, path, left-node->val));
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    return 0;
}
