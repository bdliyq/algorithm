// Question: https://leetcode.com/problems/anagrams/

#include "headers.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            if (m.count(copy) == 0) {
                m[copy] = vector<string>{s};
            } else {
                m[copy].push_back(s);
            }
        }

        vector<vector<string>> ans;
        for (auto i : m) {
            auto v = i.second;
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    // vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (auto v : ans) {
        for (auto str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
