// Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include "headers.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums.at(mid) >= nums.at(left) && nums.at(mid) <= nums.at(right)) {
                return nums.at(left);
            } else if (nums.at(mid) <= nums.at(left) && nums.at(mid) <= nums.at(right)) {
                right = mid;
            } else if (nums.at(mid) >= nums.at(left) && nums.at(mid) >= nums.at(right)) {
                left = mid+1;
            }
        }
        return nums.at(left);
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<int> nums{1};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums{1,2};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums{1,2,3};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums{4,5,6,7,8,1,2,3};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums{7,8,1,2,3,4,5,6};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums{1,2,3,4,5};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums{2,1};
        cout << s.findMin(nums) << endl;
    }
}
