// Question: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> dict;
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";

        vector<char> path;
        vector<string> ans;
        helper(digits, 0, dict, path, ans);
        return ans;
    }

private:
    void helper(string& digits, int cursor, map<char, string>& dict, vector<char>& path, vector<string>& ans) {
        if (cursor == digits.size()) {
            if (!path.empty()) {
                ans.push_back(vector_to_string(path));
            }
            return;
        }

        if (dict.count(digits.at(cursor)) > 0) {
            string keys = dict[digits.at(cursor)];
            for (int j = 0; j < keys.size(); ++j) {
                path.push_back(keys.at(j));
                helper(digits, cursor+1, dict, path, ans);
                path.pop_back();
            }
        }
    }

    string vector_to_string(vector<char>& path) {
        stringstream ss;
        for (int i = 0; i < path.size(); ++i) {
            ss << path.at(i);
        }
        return ss.str();
    }
};

int main(int argc, char** argv) {
    string digits = "234";
    Solution s;
    vector<string> ans = s.letterCombinations(digits);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans.at(i) << endl;
    }
    return 0;
}
