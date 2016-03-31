// Question: 一群人排队，每个人有（height，Tvalue），height标示身高，Tvalue标示前面有几个人比当前人身高要高。然后打乱排序，要求恢复。

#include "headers.h"

vector<int> solve(vector<int> heights, vector<int> tvalue) {
    vector<int> ans(heights.size(), 0);
    sort(heights.begin(), heights.end());
    for (int i = (int)tvalue.size() - 1; i >= 0; --i) {
        ans[i] = heights[i-tvalue[i]];
        heights.erase(heights.begin() + i - tvalue[i]);
    }
    return ans;
}

int main(int argc, char** argv) {
    auto ans = solve(vector<int>{1,2,3,4,5}, vector<int>{0,1,2,1,0});
    for (auto n : ans) {
        cout << n << " ";
    }
}
