// Question: https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        C.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            add(i+1, nums[i]);
        }
    }

    void update(int i, int val) {
        int old = sum(i+1) - sum(i);
        int diff = val - old;
        add(i+1, diff);
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


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
