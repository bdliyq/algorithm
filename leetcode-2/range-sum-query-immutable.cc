// Question: https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        C.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            C[i+1] = C[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return C[j+1] - C[i];
    }

private:
    vector<int> C;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
