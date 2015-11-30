// Question: https://leetcode.com/problems/find-peak-element/

#include "headers.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid+1]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,1};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}
