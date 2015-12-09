// Question: https://leetcode.com/problems/repeated-dna-sequences/

#include "headers.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        unordered_set<string> ans_added;

        for (int i = 0; i + 9 < s.size(); ++i) {
            string sub = s.substr(i, 10);
            if (visited.count(sub) > 0) {
                if (ans_added.count(sub) == 0) {
                    ans.push_back(sub);
                    ans_added.insert(sub);
                }
            } else {
                visited.insert(sub);
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> ans = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto str : ans) {
        cout << str << " ";
    }
    cout << endl;
}
