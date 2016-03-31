// Question: 写一个shuffle算法，使得A[0]<=A[1]>=A[2]<=A[3]...

#include "headers.h"

void solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 2; i < nums.size(); i += 2) {
        swap(nums[i-1], nums[i]);
    }
}

int main(int argc, char** argv) {
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    solve(nums);
    for (auto n : nums) {
        cout << n << " ";
    }

    return 0;
}
