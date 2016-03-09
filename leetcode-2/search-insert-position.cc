// Question: https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        int i = 0, j = len-1;
        while (i <= j) {
            int m = i + (j-i) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                j = m-1;
            } else {
                i = m+1;
            }
        }
        return i;
    }
};
