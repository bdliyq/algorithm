// Question: https://leetcode.com/problems/trapping-rain-water/

#include "headers.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        if (height.empty()) {
            return ans;
        }

        int second_hei = INT_MIN;
        int left = 0;
        int right = height.size()-1;
        while (left < right) {
            if (height[left] < height[right]) {
                second_hei = max(second_hei, height[left]);
                ans += second_hei - height[left];
                ++left;
            } else {
                second_hei = max(second_hei, height[right]);
                ans += second_hei - height[right];
                --right;
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}
