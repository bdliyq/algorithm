// Question: int数组，有重复，给定一个minimal distance，要求重复的元素距离不能小于该distance。如果不能满足要求，则返回false。

#include "headers.h"

bool solve(vector<int>& nums, int dist) {
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());

    vector<int> cursors;
    for (int i = 0; i < nums.size(); i += dist) {
        cursors.push_back(i);
    }

    int i = 0;
    while (i < nums.size()) {
        for (int j = 0; j < cursors.size(); ++j) {
            if (i >= nums.size()) {
                break;
            }

            int idx = cursors[j];
            if (idx >= nums.size()) {
                continue;
            }

            if (idx % dist != 0 && nums[idx-1] == v[i]) {
                return false;
            }

            nums[idx] = v[i];
            ++i;
            cursors[j]++;
        }
    }
}

int main(int argc, char** argv) {
    vector<int> nums{1,2,2,3,1,1,1,1};
    bool ans = solve(nums, 2);
    cout << (ans ? "true" : "false") << endl;
    for (auto n : nums) {
        cout << n << " ";
    }
}
