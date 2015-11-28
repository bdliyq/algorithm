// Question: https://leetcode.com/problems/rotate-array/

#include "headers.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0 || k % nums.size() == 0) {
            return;
        }
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(int argc, char** argv) {
    vector<int> nums{1,2,3,4,5,6,7};
    int k = 3;
    Solution s;
    s.rotate(nums, k);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
