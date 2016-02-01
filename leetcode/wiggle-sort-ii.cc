// Question: https://leetcode.com/problems/wiggle-sort-ii/

#include "headers.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int mid = len % 2 == 0 ? len/2-1 : len/2;
        vector<int> sorted = nums;
        int idx = 0;
        for (int i = 0; i <= mid; ++i) {
            nums[idx] = sorted[mid - i];
            if (idx + 1 < len) {
                nums[idx+1] = sorted[len - i - 1];
            }
            idx += 2;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1, 5, 1, 1, 6, 4};
    s.wiggleSort(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
}
