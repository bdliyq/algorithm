// Question: https://leetcode.com/problems/single-number/

#include "headers.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto n : nums) {
            ans ^= n;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3,4,5,1,2,3,4};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
