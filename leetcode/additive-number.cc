// Question: https://leetcode.com/problems/additive-number/

#include "headers.h"

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int i = 1; i <= (len-1)/2; ++i) {
            if (i > 1 && num[0] == '0') {
                continue;
            }
            for (int j = i+1; len-j >= max(j-i, i); ++j) {
                if (j-i > 1 && num[i] == '0') {
                    continue;
                }
                long n1 = atol(num.substr(0, i).c_str());
                long n2 = atol(num.substr(i, j-i).c_str());
                if (helper(num.substr(j), n1, n2)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool helper(string num, long n1, long n2) {
        if (num.empty()) {
            return true;
        }
        long sum = n1 + n2;
        stringstream ss;
        ss << sum;
        if (num.find(ss.str()) == 0) {
            return helper(num.substr(ss.str().size()), n2, sum);
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isAdditiveNumber("199100199") << endl;
    return 0;
}
