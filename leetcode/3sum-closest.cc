// Question: https://leetcode.com/problems/3sum-closest/

#include <vector>
#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(target - sum);
                if (min_diff > diff) {
                    min_diff = diff;
                    ans = sum;
                }
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    Solution s;
    cout << s.threeSumClosest(nums, 1) << endl;
    return 0;
}
