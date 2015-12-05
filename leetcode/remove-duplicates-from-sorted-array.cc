// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include "headers.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                ++i;
                swap(nums[i], nums[j]);
            }
            ++j;
        }
        return min((int)nums.size(), i+1);
    }

private:
    void swap(int& x, int& y) {
        int t = x;
        x = y;
        y = t;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,1,2,2,2,3,3,4,5,5,6};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
