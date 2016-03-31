// Question: 给定一个数组，求里面的unordered pair。例如：｛1，2，3｝，返回空；｛1，3，2｝，返回｛3，2｝；｛3，2，1｝，返回｛3，2｝，｛3，1｝，｛2，1｝

#include "headers.h"

vector<pair<int, int>> solve(vector<int> nums) {
    vector<pair<int, int>> ans;

    int len = nums.size();
    if (len <= 1) {
        return ans;
    }

    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            if (nums[i] > nums[j]) {
                ans.push_back({nums[i], nums[j]});
            }
        }
    }
    return ans;
}

int main(int argc, char** argv) {
    auto ans = solve(vector<int>{3,2,1});
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}
