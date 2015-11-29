// Question: https://leetcode.com/problems/unique-binary-search-trees-ii/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return vector<TreeNode*>();
        }
        return helper(1, n);
    }

private:
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> ans;
        if (start == end) {
            ans.push_back(new TreeNode(start));
        } else if (start < end) {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> left = helper(start, i-1);
                vector<TreeNode*> right = helper(i+1, end);
                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        ans.push_back(root);
                    }
                }
            }
        } else {
            ans.push_back(NULL);
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<TreeNode*> ans = s.generateTrees(3);
}
