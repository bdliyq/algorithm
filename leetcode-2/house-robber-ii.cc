// Question: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        return max(helper(nums, 0, (int)nums.size() - 2), helper(nums, 1, (int)nums.size() - 1));
    }

    int helper(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        int i = nums[start];
        int j = max(nums[start], nums[start+1]);
        for (int k = start+2; k <= end; ++k) {
            int r = max(j, nums[k] + i);
            i = j;
            j = r;
        }
        return j;
    }
};
