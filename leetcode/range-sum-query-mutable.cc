// Question: https://leetcode.com/problems/range-sum-query-mutable/

#include "headers.h"

class NumArray {
public:
    NumArray(vector<int> &nums) {
        C.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            add(i+1, nums.at(i));
        }
    }

    void update(int i, int val) {
        int v = sum(i+1) - sum(i);
        int d = val - v;
        add(i+1, d);
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }

private:
    int lowbit(int i) {
        return i & -i;
    }

    void add(int i, int v) {
        if (i == 0) {
            return;
        }

        while (i < C.size()) {
            C[i] += v;
            i += lowbit(i);
        }
    }

    int sum(int i) {
        int v = 0;
        while (i > 0) {
            v += C[i];
            i -= lowbit(i);
        }
        return v;
    }

private:
    vector<int> C;
};


int main(int argc, char** argv) {
// Your NumArray object will be instantiated and called as such:
    vector<int> nums{1,3,5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
