// Question: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include "headers.h"

struct MyTreeNode{
    int val;
    int sum;
    int dup;
    MyTreeNode* left;
    MyTreeNode* right;
    MyTreeNode(int v) : val(v), sum(0), dup(1), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }

        vector<int> ans(nums.size(), 0);
        MyTreeNode* root = NULL;
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            root = insert(nums[i], root, ans, i, 0);
        }
        return ans;
    }

private:
    MyTreeNode* insert(int num, MyTreeNode* node, vector<int>& ans, int idx, int presum) {
        if (!node) {
            node = new MyTreeNode(num);
            ans[idx] = presum;
        } else if (node->val == num) {
            node->dup++;
            ans[idx] = presum + node->sum;
        } else if (node->val > num) {
            node->sum++;
            node->left = insert(num, node->left, ans, idx, presum);
        } else {
            node->right = insert(num, node->right, ans, idx, presum + node->sum + node->dup);
        }
        return node;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{5, 2, 6, 1};
    auto ans = s.countSmaller(nums);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
