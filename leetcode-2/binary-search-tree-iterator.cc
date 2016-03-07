// Question: https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root) {
            stack<TreeNode*> s;
            auto node = root;
            while (node || !s.empty()) {
                if (node) {
                    s.push(node);
                    node = node->right;
                } else {
                    node = s.top();
                    s.pop();
                    data_.push(node->val);
                    node = node->left;
                }
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !data_.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ans = data_.top();
        data_.pop();
        return ans;
    }

private:
    stack<int> data_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
