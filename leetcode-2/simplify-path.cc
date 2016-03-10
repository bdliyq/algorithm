// Question: https://leetcode.com/problems/simplify-path/

#include "headers.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs = split(path, '/');

        stack<string> s;
        for (string dir : dirs) {
            if (dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (!dir.empty()) {
                s.push(dir);
            }
        }
        string ans = "";
        while (!s.empty()) {
            if (ans.empty()) {
                ans = s.top();
            } else {
                ans = s.top() + "/" + ans;
            }
            s.pop();
        }
        return "/" + ans;
    }

    vector<string> split(string path, char c) {
        vector<string> ans;
        int i = 0, j = 0;
        while (j < path.size()) {
            if (path[j] == c) {
                ans.push_back(path.substr(i, j-i));
                i = j+1;
            }
            ++j;
        }
        if (j > i) {
            ans.push_back(path.substr(i, j-i));
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/") << endl;
}
