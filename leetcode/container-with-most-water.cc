// Question: https://leetcode.com/problems/container-with-most-water/

#include "headers.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }

        int left = 0;
        int right = height.size() - 1;
        int ans = INT_MIN;
        int second_hei = INT_MIN;
        while (left < right) {
            if (height.at(left) < height.at(right)) {
                second_hei = max(height.at(left), second_hei);
                int t = second_hei * (right - left);
                ans = max(ans, t);
                ++left;
            } else {
                second_hei = max(height.at(right), second_hei);
                int t = second_hei * (right - left);
                ans = max(ans, t);
                --right;
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> height{4,2,5,1,7,1};
    cout << s.maxArea(height) << endl;
}
