// Question: https://leetcode.com/problems/sort-colors/

#include "headers.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;
        while (i < nums.size() && j >= 0 && k <= j) {
            if (nums[k] == 0) {
                swap(nums[i], nums[k]);
                if (k == i) {
                    ++k;
                }
                ++i;
            } else if (nums[k] == 1) {
                ++k;
            } else {
                swap(nums[k], nums[j]);
                --j;
            }
        }
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
    vector<int> nums{2,1};
    s.sortColors(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
