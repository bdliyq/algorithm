// Question: https://leetcode.com/problems/pascals-triangle-ii/

#include "headers.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        for (int i = 1; i < rowIndex+1; ++i) {
            for (int j = i-1; j >= 1; --j) {
                ans[j] = ans[j-1] + ans[j];
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> ans = s.getRow(3);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
