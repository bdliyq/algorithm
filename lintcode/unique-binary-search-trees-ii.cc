/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return this->dfs(1, n);
    }
private:
    vector<TreeNode *> dfs(int i, int j) {
        vector<TreeNode *> ans;
        if (i > j) {
            ans.push_back(NULL);
            return ans;
        }
        if (i == j) {
            ans.push_back(new TreeNode(i));
            return ans;
        }
        for (int p = i; p <= j; ++p) {
            vector<TreeNode *> ans_left = this->dfs(i, p-1);
            vector<TreeNode *> ans_right = this->dfs(p+1, j);
            for (int q = 0; q < ans_left.size(); ++q) {
                for (int r = 0; r < ans_right.size(); ++r) {
                    TreeNode *root = new TreeNode(p);
                    root->left = ans_left[q];
                    root->right = ans_right[r];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
