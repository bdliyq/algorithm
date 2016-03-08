// Question: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = (int)nums.size() - 1;
        while (true) {
            int i = partition(nums, start, end);
            if (i == k-1) {
                return nums[i];
            } else if (i < k-1) {
                start = i+1;
            } else {
                end = i-1;
            }
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int i = start, j = end;
        int pivot = nums[i];
        while (i < j) {
            while (i < j && nums[j] <= pivot) {
                --j;
            }
            if (i < j) {
                nums[i] = nums[j];
                ++i;
            }

            while (i < j && nums[i] >= pivot) {
                ++i;
            }
            if (i < j) {
                nums[j] = nums[i];
                --j;
            }
        }
        nums[i] = pivot;
        return i;
    }
};
