// Question: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<string, string> dict;
        dict["2"] = "abc";
        dict["3"] = "def";
        dict["4"] = "ghi";
        dict["5"] = "jkl";
        dict["6"] = "mno";
        dict["7"] = "pqrs";
        dict["8"] = "tuv";
        dict["9"] = "wxyz";
        vector<string> path;
        vector<string> ans;
        helper(digits, 0, dict, path, ans);
        return ans;
    }

    void helper(string digits, int start, unordered_map<string, string>& dict, vector<string>& path, vector<string>& ans) {
        if (start == digits.size()) {
            if (path.size() == digits.size()) {
                stringstream ss;
                for (auto s : path) {
                    ss << s;
                }
                ans.push_back(ss.str());
            }
        } else if (start < digits.size()) {
            for (int i = start; i < digits.size(); ++i) {
                string k = digits.substr(i, 1);
                if (dict.count(k) > 0) {
                    for (int j = 0; j < dict[k].size(); ++j) {
                        path.push_back(dict[k].substr(j, 1));
                        helper(digits, i+1, dict, path, ans);
                        path.pop_back();
                    }
                }
            }
        }
    }
};
