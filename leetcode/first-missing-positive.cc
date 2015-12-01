// Question: https://leetcode.com/problems/first-missing-positive/

#include "headers.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i+1) {
                continue;
            }

            while (nums[i] != i+1 && nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                int t = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = t;
            }
        }

        int ans = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<int> nums{1,1};
        cout << s.firstMissingPositive(nums) << endl;
    }
    {
        vector<int> nums{1,2,0};
        cout << s.firstMissingPositive(nums) << endl;
    }
    {
        vector<int> nums{3,4,-1,1};
        cout << s.firstMissingPositive(nums) << endl;
    }
}
