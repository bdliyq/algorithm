// Question: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes = split(preorder, ',');
        int depth = 0;
        for (int i = 0; i < (int)nodes.size()-1; ++i) {
            auto n = nodes[i];
            if (n == "#") {
                --depth;
                if (depth < 0) {
                    return false;
                }
            } else {
                ++depth;
            }
        }
        return depth != 0 ? false : nodes.back() == "#";
    }

    vector<string> split(string data, char c) {
        int begin = 0;
        int end = 0;
        vector<string> ans;
        while (end < data.size()) {
            if (data[end] == c) {
                ans.push_back(data.substr(begin, end-begin));
                begin = end+1;
            }
            ++end;
        }
        if (end > begin) {
            ans.push_back(data.substr(begin, end-begin));
        }
        return ans;
    }

};
