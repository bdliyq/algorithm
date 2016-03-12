// Question: https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) {
            return false;
        }

        unordered_set<int> s;
        while (n != 1) {
            if (s.count(n) > 0) {
                break;
            }
            s.insert(n);

            int t = n;
            n = 0;
            while (t != 0) {
                n += pow(t%10, 2);
                t /= 10;
            }
        }

        return n == 1;
    }
};
