// Question: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for (auto n : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += n;
            ans = max(ans, sum);
        }
        return ans;
    }
};
