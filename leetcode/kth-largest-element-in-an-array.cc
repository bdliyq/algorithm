// Question: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include "headers.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int p = -1;
        while (true) {
            p = partition(nums, left, right);
            if (p == k-1) {
                return nums[p];
            } else if (p < k-1) {
                left = p+1;
            } else {
                right = p-1;
            }
        }
        return -1;
    }

private:
    int partition(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        swap(nums[mid], nums[start]);
        int pivot = nums[start];
        int left = start;
        int right = end;
        while (left < right) {
            while (left < right && nums[right] < pivot) {
                --right;
            }
            if (left < right) {
                nums[left] = nums[right];
                ++left;
            }

            while (left < right && nums[left] >= pivot) {
                ++left;
            }
            if (left < right) {
                nums[right] = nums[left];
                --right;
            }
        }
        nums[left] = pivot;
        return left;
    }

    void swap(int& x, int& y) {
        int t = x;
        x = y;
        y = t;
    }

    void print_vec(vector<int>& nums) {
        for (auto n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 2) << endl;
    return 0;
}
