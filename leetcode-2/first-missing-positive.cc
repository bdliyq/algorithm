// Question: https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while (i < len) {
            int j = i;
            while (nums[j] > 0 && nums[j] <= len && nums[j] != j+1 && nums[j] != nums[nums[j]-1]) {
                int t = nums[nums[j]-1];
                nums[nums[j]-1] = nums[j];
                nums[j] = t;
            }
            ++i;
        }
        for (int i = 0; i < len; ++i) {
            if (i+1 != nums[i]) {
                return i+1;
            }
        }
        return len+1;
    }
};
