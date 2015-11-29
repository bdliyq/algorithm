// Question: https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
        ans.push_back(root->val);
        recur(root->left, ans);
        recur(root->right, ans);
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
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }

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
        vector<int> ans = s.preorderTraversal(root);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
