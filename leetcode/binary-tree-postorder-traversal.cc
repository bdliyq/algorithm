// Question: https://leetcode.com/problems/binary-tree-postorder-traversal/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return iterate(root);

        // vector<int> ans;
        // recur(root, ans);
        // return ans;
    }

private:
    void recur(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }
        if (root->left) {
            recur(root->left, ans);
        }
        if (root->right) {
            recur(root->right, ans);
        }
        ans.push_back(root->val);
    }

    vector<int> iterate(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        TreeNode* root = new TreeNode(100);
        root->left = new TreeNode(200);
        root->left->left = new TreeNode(300);
        root->left->right = new TreeNode(1000);
        root->right = new TreeNode(400);
        root->right->left = new TreeNode(500);
        vector<int> ans = s.postorderTraversal(root);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
