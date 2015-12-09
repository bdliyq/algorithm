// Question: https://leetcode.com/problems/sum-root-to-leaf-numbers/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (!root) {
            return ans;
        }

        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(root->val, root));
        while (!q.empty()) {
            pair<int, TreeNode*> p = q.front();
            q.pop();

            TreeNode* n = p.second;
            if (!n->left && !n->right) {
                ans += p.first;
            } else {
                if (n->left) {
                    q.push(make_pair(10 * p.first + n->left->val, n->left));
                }
                if (n->right) {
                    q.push(make_pair(10 * p.first + n->right->val, n->right));
                }
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
    cout << s.sumNumbers(root) << endl;
}
