// Question: https://leetcode.com/problems/minimum-size-subarray-sum/

#include "headers.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0;
        int j = i;
        int sum = 0;
        int ans = INT_MAX;

        while (j < nums.size()) {
            if (sum+nums[j] >= s) {
                ans = min(ans, j-i+1);
                sum -= nums[i];
                ++i;
            } else {
                sum += nums[j];
                ++j;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }

};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,4,5};
    cout << s.minSubArrayLen(11, nums) << endl;
    return 0;
}
