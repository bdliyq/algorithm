// Question: Four integer.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void swap(vector<int>& arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

vector<int> four_integer(int a, int b, int c, int d) {
    vector<int> ans(4, 0);
    ans[0] = a;
    ans[1] = b;
    ans[2] = c;
    ans[3] = d;
    sort(ans.begin(), ans.end());

    swap(ans, 0, 1);
    swap(ans, 2, 3);
    swap(ans, 0, 3);
    return ans;
}

int main(int argc, char** argv) {
    vector<int> ans = four_integer(1,2,3,4);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans.at(i) << endl;
    }
}
