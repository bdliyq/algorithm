// Question: https://leetcode.com/problems/search-insert-position/

#include "headers.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,3,5,6};
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    cout << s.searchInsert(nums, 7) << endl;
    cout << s.searchInsert(nums, 0) << endl;
    return 0;
}
