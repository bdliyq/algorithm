// Question: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                v.push_back("#");
            } else {
                stringstream ss;
                ss << node->val;
                v.push_back(ss.str());
                q.push(node->left);
                q.push(node->right);
            }
        }

        string ans("");
        for (auto s : v) {
            if (!ans.empty()) {
                ans += " ";
            }
            ans += s;
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data, ' ');
        if (v[0] == "#") {
            return NULL;
        }
        TreeNode* root = new TreeNode(atoi(v[0].c_str()));
        vector<TreeNode*> vec{root};
        int i = 1;
        int j = 0;
        while (i < v.size()) {
            while (j < vec.size() && !vec[j]) {
                ++j;
            }

            if (j >= vec.size()) {
                break;
            }

            if (v[i] == "#") {
                vec[j]->left = NULL;
            } else {
                vec[j]->left = new TreeNode(atoi(v[i].c_str()));
            }
            vec.push_back(vec[j]->left);
            ++i;
            if (v[i] == "#") {
                vec[j]->right = NULL;
            } else {
                vec[j]->right = new TreeNode(atoi(v[i].c_str()));
            }
            vec.push_back(vec[j]->right);
            ++i;
            ++j;
        }
        return root;
    }

private:
    vector<string> split(string s, char c) {
        vector<string> v;
        int begin = 0;
        int end = 0;
        while (end < s.size()) {
            if (s[end] == c) {
                v.push_back(s.substr(begin, end-begin));
                begin = end + 1;
            }
            ++end;
        }
        if (end - begin > 0) {
            v.push_back(s.substr(begin, end-begin));
        }
        return v;
    }
};

int main(int argc, char** argv) {
// Your Codec object will be instantiated and called as such:
    Codec codec;
    TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    // root->left->left = new TreeNode(1);
    string s = codec.serialize(root);
    cout << s << endl;
    TreeNode* newroot = codec.deserialize(s);
    // cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->left->left->val << endl;
}
