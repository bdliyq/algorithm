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
        // return iterate(root);

        return threaded_way(root);

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

    vector<int> threaded_way(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }

        TreeNode* current = NULL;
        TreeNode* pre = NULL;

        current = root;
        while (current) {
            if (current->left == NULL) {
                ans.push_back(current->val);
                current = current->right;
            } else {
                pre = current->left;
                while (pre->right && pre->right != current) {
                    pre = pre->right;
                }

                if (pre->right) {
                    pre->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                } else {
                    pre->right = current;
                    current = current->left;
                }
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
