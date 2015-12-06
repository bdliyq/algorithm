// Question: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, (int)inorder.size()-1, 0, (int)postorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inleft, int inright, int poleft, int poright) {
        if (inleft > inright) {
            return NULL;
        }

        if (inleft == inright) {
            return new TreeNode(inorder[inleft]);
        }

        TreeNode* root = new TreeNode(postorder[poright]);
        int place = inleft;
        while (inorder[place] != postorder[poright]) {
            ++place;
        }
        root->left = helper(inorder, postorder, inleft, place-1, poleft, poleft + place-inleft-1);
        root->right = helper(inorder, postorder, place+1, inright, poleft + place-inleft, poright-1);
        return root;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> inorder{1,2};
    vector<int> postorder{2,1};
    // auto it = find(inorder.begin(), inorder.end(), 1);
    // vector<int> t1(inorder.begin(), it);
    // vector<int> t2(++it, inorder.end());
    // vector<int> t3(postorder.begin(), postorder.begin()+t2.size()+1);
    // for (auto i : t3) {
    //     cout << i << " ";
    // }
    // cout << endl;
    TreeNode* root = s.buildTree(inorder, postorder);
}
