// Question: https://leetcode.com/problems/longest-consecutive-sequence/

#include "headers.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for (int n : nums) {
            if (s.count(n) > 0) {
                int r = 1;
                int i = n + 1;
                while (s.count(i) > 0) {
                    s.erase(i);
                    ++i;
                    ++r;
                }
                i = n - 1;
                while (s.count(i) > 0) {
                    s.erase(i);
                    --i;
                    ++r;
                }
                ans = max(ans, r);
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}
