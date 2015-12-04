// Question: https://leetcode.com/problems/house-robber/

#include "headers.h"

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
            int r = max(j, i+nums[k]);
            i = j;
            j = r;
        }

        return j;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{3,8,4,9,1,1,1,3};
    cout << s.rob(nums) << endl;
}
