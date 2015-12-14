// Question: https://leetcode.com/problems/range-sum-query-immutable/

#include "headers.h"

class NumArray {
public:
    NumArray(vector<int> &nums) {
        C.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            C[i+1] = C[i] + nums.at(i);
        }
    }

    int sumRange(int i, int j) {
        return C[j+1] - C[i];
    }

private:
    vector<int> C;
};

int main(int argc, char** argv) {
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray na(nums);
    cout << na.sumRange(0, 2) << endl;
    cout << na.sumRange(2, 5) << endl;
    cout << na.sumRange(0, 5) << endl;
    return 0;
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
