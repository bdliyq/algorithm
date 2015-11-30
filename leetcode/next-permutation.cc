// Question: https://leetcode.com/problems/next-permutation/

#include "headers.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i+1] > nums[i]) {
                for (int j = nums.size()-1; j >= i; --j) {
                    if (nums[j] > nums[i]) {
                        int t = nums[i];
                        nums[i] = nums[j];
                        nums[j] = t;
                        reverse(nums.begin()+i+1, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{6,8,7,4,3,2};
    s.nextPermutation(nums);
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
