// Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = (int)nums.size()-1;
        while (l < r) {
            int m = l + (r-l)/2;
            if (nums[m] <= nums[l] && nums[m] <= nums[r]) {
                r = m;
            } else if (nums[m] >= nums[l] && nums[m] >= nums[r]) {
                l = m+1;
            } else {
                return nums[l];
            }
        }
        return nums[l];
    }
};
