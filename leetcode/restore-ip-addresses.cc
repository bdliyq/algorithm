// Question: https://leetcode.com/problems/restore-ip-addresses/

#include "headers.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> path;
        helper(s, path, ans);
        return ans;
    }

private:
    void helper(string s, vector<string>& path, vector<string>& ans) {
        if (s.empty()) {
            if (path.size() == 4) {
                string r("");
                for (int i = 0; i < path.size(); ++i) {
                    if (i > 0) {
                        r += ".";
                    }
                    r += path[i];
                }
                ans.push_back(r);
            }
        } else {
            if (path.size() < 4) {
                for (int j = 1; j <= min(3, (int)s.size()); ++j) {
                    string part = s.substr(0, j);
                    if (part.size() > 1 && part[0] == '0') {
                        continue;
                    }
                    if (part.size() > 0 && atoi(part.c_str()) <= 255) {
                        path.push_back(part);
                        helper(s.substr(j), path, ans);
                        path.pop_back();
                    }
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> ans = s.restoreIpAddresses("0000");
    for (auto v : ans) {
        cout << v << endl;
    }
    return 0;
}
