// Question: https://leetcode.com/problems/remove-element/

#include "headers.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                swap(nums[i], nums[j]);
                ++i;
            }
            ++j;
        }
        return i;
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
    vector<int> nums{1,2,1,3,1,4,1,5};
    cout << s.removeElement(nums, 1) << endl;
    return 0;
}
