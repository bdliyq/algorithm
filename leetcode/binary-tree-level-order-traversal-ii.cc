// Question: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int curr_level_count = 1;
        int next_level_count = 0;
        vector<int> level_vec;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            level_vec.push_back(node->val);

            if (node->left) {
                ++next_level_count;
                q.push(node->left);
            }
            if (node->right) {
                ++next_level_count;
                q.push(node->right);
            }

            if (--curr_level_count == 0) {
                curr_level_count = next_level_count;
                next_level_count = 0;
                ans.insert(ans.begin(), level_vec);
                level_vec.clear();
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode *root = new TreeNode(10);
    vector<vector<int>> ans = s.levelOrderBottom(root);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
