// Question: https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                swap(nums[i], nums[j]);
                ++i;
            }
            ++j;
        }
        return i;
    }
};
