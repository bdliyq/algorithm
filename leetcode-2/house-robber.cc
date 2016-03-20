// Question: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        int i = nums[0];
        int j = max(nums[0], nums[1]);
        for (int k = 2; k < nums.size(); ++k) {
            int r = max(j, nums[k] + i);
            i = j;
            j = r;
        }
        return j;
    }
};
