// Question: https://leetcode.com/problems/maximum-subarray/

#include "headers.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{-1,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
}
