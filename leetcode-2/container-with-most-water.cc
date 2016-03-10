// Question: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int second_hei = INT_MIN;
        int ans = INT_MIN;
        while (l < r) {
            if (height[l] < height[r]) {
                second_hei = max(second_hei, height[l]);
                ans = max(ans, (r-l) * second_hei);
                ++l;
            } else {
                second_hei = max(second_hei, height[r]);
                ans = max(ans, (r-l) * second_hei);
                --r;
            }
        }
        return ans;
    }
};
