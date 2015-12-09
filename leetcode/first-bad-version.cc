// Question: https://leetcode.com/problems/first-bad-version/

#include "headers.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};

bool isBadVersion(int version) {
    if (version >= 1702766719) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    Solution s;
    cout << s.firstBadVersion(2126753390) << endl;
}
