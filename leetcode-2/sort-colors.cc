// Question: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                swap(nums[i], nums[j]);
                ++j;
            }
            ++i;
        }

        i = (int)nums.size() - 1;
        j = (int)nums.size() - 1;
        while (i >= 0) {
            if (nums[i] == 2) {
                swap(nums[i], nums[j]);
                --j;
            }
            --i;
        }
    }
};
