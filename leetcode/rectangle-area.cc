// Question: https://leetcode.com/problems/rectangle-area/

#include "headers.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(A-C) * abs(B-D);
        int area2 = abs(E-G) * abs(F-H);
        int ans = area1 + area2;
        if (C < E || A > G || B > H || D < F) {
            return ans;
        }

        vector<int> x{A, C, E, G};
        sort(x.begin(), x.end());
        vector<int> y{B, D, F, H};
        sort(y.begin(), y.end());

        return ans - (x[2]-x[1]) * (y[2]-y[1]);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
