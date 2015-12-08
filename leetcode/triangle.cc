// Question: https://leetcode.com/problems/triangle/

#include "headers.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }

        vector<int> dp((int)triangle.size(), INT_MAX);
        for (int i = 0; i < (int)triangle.back().size(); ++i) {
            dp[i] = triangle.back().at(i);
        }
        for (int i = (int)triangle.size()-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle.at(i).at(j);
            }
        }

        return dp[0];
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> triangle;
    triangle.push_back(vector<int>{2});
    triangle.push_back(vector<int>{3,4});
    triangle.push_back(vector<int>{6,5,7});
    triangle.push_back(vector<int>{4,1,8,3});
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
