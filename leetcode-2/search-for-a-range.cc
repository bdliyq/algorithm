// Question: https://leetcode.com/problems/search-for-a-range/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums, target);
        int r = lower_bound(nums, target+1);
        if (l < nums.size() && nums[l] == target) {
            return vector<int>{l, r-1};
        }

        return vector<int>{-1, -1};
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return l;
    }
};
