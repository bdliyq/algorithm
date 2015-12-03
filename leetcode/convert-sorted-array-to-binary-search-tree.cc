// Question: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_vec(vector<int>& nums) {
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }

        return helper(nums, 0, (int)nums.size()-1);
    }

private:
    TreeNode* helper(vector<int>& nums, int i, int j) {
        if (i > j || i >= nums.size() || j >= nums.size() || i < 0 || j < 0) {
            return NULL;
        }

        if (i == j) {
            return new TreeNode(nums[i]);
        }

        int mid = (i+j)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, i, mid-1);
        root->right = helper(nums, mid+1, j);
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
}
