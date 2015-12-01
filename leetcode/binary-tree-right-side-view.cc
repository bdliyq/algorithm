// Question: https://leetcode.com/problems/binary-tree-right-side-view/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int curr_level_count = 1;
        int next_level_count = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                ++next_level_count;
            }
            if (node->right) {
                q.push(node->right);
                ++next_level_count;
            }
            --curr_level_count;
            if (curr_level_count == 0) {
                ans.push_back(node->val);
                curr_level_count = next_level_count;
                next_level_count = 0;
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    return 0;
}
