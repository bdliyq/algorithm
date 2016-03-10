// Question: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int ans = 0;
        int second_hei = INT_MIN;
        while (l < r) {
            if (height[l] < height[r]) {
                second_hei = max(second_hei, height[l]);
                ans += second_hei - height[l];
                l++;
            } else {
                second_hei = max(second_hei, height[r]);
                ans += second_hei - height[r];
                r--;
            }
        }
        return ans;
    }
};
