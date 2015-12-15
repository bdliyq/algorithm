// Question: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include "headers.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] < nums[l]) {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (nums[m] > nums[r]) {
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
     }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{3,1};
    cout << s.search(nums, 1) << endl;
    cout << s.search(nums, 5) << endl;
    cout << s.search(nums, 3) << endl;
}
