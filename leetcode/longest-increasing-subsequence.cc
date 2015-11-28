// Question: https://leetcode.com/problems/longest-increasing-subsequence/

#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int ans = INT_MIN;
        for (auto i = dp.begin(); i != dp.end(); ++i) {
            ans = max(*i, ans);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl;
}
