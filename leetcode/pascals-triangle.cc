// Question: https://leetcode.com/problems/pascals-triangle/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) {
            return ans;
        }
        ans.push_back(vector<int>{1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> line(i+1, 1);
            for (int j = 1; j < i; ++j) {
                line[j] = ans.back().at(j-1) + ans.back().at(j);
            }
            ans.push_back(line);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    auto ans = s.generate(5);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
