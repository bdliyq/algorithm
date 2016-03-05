// Question: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!ss.str().empty()) {
                ss << " ";
            }
            if (!node) {
                ss << "#";
            } else {
                ss << node->val;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data, ' ');
        if (v.size() == 0) {
            return NULL;
        }
        vector<TreeNode*> nodes;
        TreeNode* root = new TreeNode(atoi(v[0].c_str()));
        nodes.push_back(root);

        int i = 1;
        int j = 0;
        while (i < v.size()) {
            while (j < nodes.size() && !nodes[j]) {
                ++j;
            }

            if (j >= nodes.size()) {
                break;
            }

            if (v[i] == "#") {
                nodes[j]->left = NULL;
            } else {
                nodes[j]->left = new TreeNode(atoi(v[i].c_str()));
            }
            nodes->push_back(nodes[j]->left);

            ++i;
            if (v[i] == "#") {
                nodes[j]->right = NULL;
            } else {
                nodes[j]->right = new TreeNode(atoi(v[i].c_str()));
            }
            nodes->push_back(nodes[j]->right);

            ++i;
            ++j;
        }

        return root;
    }

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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
