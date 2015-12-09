// Question: https://leetcode.com/problems/house-robber-ii/

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
        return max(helper(nums, 0, (int)nums.size()-2), helper(nums, 1, (int)nums.size()-1));
    }

private:
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        int i = nums[start];
        int j = max(nums[start], nums[start+1]);
        for (int idx = start+2; idx <= end; ++idx) {
            int r = max(j, nums[idx] + i);
            i = j;
            j = r;
        }

        return j;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,1,1,1};
    cout << s.rob(nums) << endl;
    return 0;
}
