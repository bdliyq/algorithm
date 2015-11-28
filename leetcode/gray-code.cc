// Question: https://leetcode.com/problems/gray-code/

#include "headers.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n < 0) {
            return ans;
        }

        ans.push_back(0);
        for (int i = 0; i < n; ++i) {
            int j = ans.size()-1;
            for (; j >= 0; --j) {
                ans.push_back(ans.at(j) | (1 << i));
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> ans = s.grayCode(2);
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
