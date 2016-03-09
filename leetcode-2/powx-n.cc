// Question: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 1.0 / (x * myPow(x, -n-1));
        }

        double half = myPow(x, n/2);
        return (n%2 == 1 ? x : 1) * half * half;
    }
};
