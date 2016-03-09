// Question: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int min_diff = INT_MAX;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1, k = len-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    ans = sum;
                }
                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    return ans;
                }
            }
        }
        return ans;
    }
};
