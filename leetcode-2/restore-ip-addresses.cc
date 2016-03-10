// Question: https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        helper(s, 0, 0, ans, "");
        return ans;
    }

    void helper(string& s, int start, int sections, vector<string>& ans, string path) {
        if (sections == 4 && start == s.size()) {
            ans.push_back(path);
        }

        if (sections < 4 && start < s.size()) {
            for (int i = 0; i < min(3, (int)s.size() - start); ++i) {
                auto sub = s.substr(start, i+1);
                if (sub.size() == 1 || (sub.size() > 1 && sub[0] != '0' && atoi(sub.c_str()) <= 255)) {
                    helper(s, start+i+1, sections+1, ans, (path.empty() ? sub : path+"."+sub));
                }
            }
        }
    }
};
