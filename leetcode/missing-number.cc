// Question: https://leetcode.com/problems/missing-number/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int ans = 0;
        for (int i = 1; i < nums.size()+1; ++i) {
            ans ^= i;
        }
        for (auto n : nums) {
            ans ^= n;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{0,1,3};
    cout << s.missingNumber(nums) << endl;
}
