// Question: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
                q.push(node->left);
                ++next_level_count;
            }
            if (node->right) {
                q.push(node->right);
                ++next_level_count;
            }

            if (--curr_level_count == 0) {
                curr_level_count = next_level_count;
                next_level_count = 0;
                if (ans.size() % 2 == 1) {
                    reverse(level_vec.begin(), level_vec.end());
                }
                ans.push_back(level_vec);
                level_vec.clear();
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<vector<int>> ans = s.zigzagLevelOrder(root);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
