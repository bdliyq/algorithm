// Question: https://leetcode.com/problems/search-for-a-range/

#include "headers.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums, target);
        int r = lower_bound(nums, target+1);
        if (l < nums.size() && nums[l] == target) {
            return vector<int>({l, r-1});
        }
        return vector<int>({-1, -1});
    }

private:
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

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    auto ans = s.searchRange(nums, 8);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
