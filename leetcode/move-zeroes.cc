// Question: https://leetcode.com/problems/move-zeroes/

#include "headers.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != 0) {
                nums[i++] = nums[j++];
            } else {
                ++j;
            }
        }
        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;
}
