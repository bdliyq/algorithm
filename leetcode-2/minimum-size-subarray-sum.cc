// Question: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        int sum = 0;
        while (j < len) {
            if (sum + nums[j] >= s) {
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
