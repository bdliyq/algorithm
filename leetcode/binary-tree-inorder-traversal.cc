// Question: https://leetcode.com/problems/binary-tree-inorder-traversal/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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

        recur(root->left, ans);
        ans.push_back(root->val);
        recur(root->right, ans);
    }

    vector<int> iterate(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }

        TreeNode* node = root;
        stack<TreeNode*> s;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
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
        vector<int> ans = s.inorderTraversal(root);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}
