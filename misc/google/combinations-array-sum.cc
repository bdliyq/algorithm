// Question: 给定一个数组和一个target，问是否存在某种分法使得各部分和加起来等于target。例如：给定｛1，5，0，6｝，target=21，则｛1，5｝｛0}{6｝加起来是21，｛1，5｝｛0，6｝加起来也是21，返回true。如果target=25，则返回false。

#include "headers.h"

int sum(vector<int>& nums, int start, int end) {
    int ans = 0;
    for (int i = start; i < end; ++i) {
        ans = ans * 10 + nums[i];
    }
    return ans;
}

bool bfs(vector<int>& nums, int target, int start) {
    if (target == 0 && start == nums.size()) {
        return true;
    }

    for (int i = start; i < nums.size(); ++i) {
        int s = sum(nums, start, i+1);
        if (target >= s) {
            if (bfs(nums, target-s, i+1)) {
                return true;
            }
        }
    }

    return false;
}

bool solve(vector<int> nums, int target) {
    return bfs(nums, target, 0);
}

int main(int argc, char** argv) {
    cout << solve(vector<int>{1,5,0,6}, 21) << endl;
    cout << solve(vector<int>{1,5,0,6}, 25) << endl;
}
