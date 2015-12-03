// Question: https://leetcode.com/problems/binary-search-tree-iterator/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root) {
            TreeNode* node = root;
            stack<TreeNode*> s;
            while (!s.empty() || node) {
                if (node) {
                    s.push(node);
                    node = node->left;
                } else {
                    node = s.top();
                    s.pop();
                    nums.push(node->val);
                    node = node->right;
                }
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nums.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ans = nums.front();
        nums.pop();
        return ans;
    }

private:
    queue<int> nums;
};

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(11);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
}
