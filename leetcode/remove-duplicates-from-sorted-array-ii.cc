// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include "headers.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2;
        int j = i;
        while (j < nums.size()) {
            if (nums[i-2] == nums[i-1] && nums[i-1] == nums[j]) {
                ++j;
            } else {
                nums[i++] = nums[j++];
            }
        }
        return min(i, (int)nums.size());
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,1,1,2,2,3};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
