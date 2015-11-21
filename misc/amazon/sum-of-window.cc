// Question: Sum of window.

#include <vector>
#include <iostream>

using namespace std;

vector<int> sum_of_window(vector<int> array, int k) {
    if (array.empty() || array.size() < k || k <= 0) {
        return vector<int>();
    }

    vector<int> ans(array.size() - k + 1, 0);
    for (int i = 0; i < k; ++i) {
        ans[0] += array.at(i);
    }
    for (size_t i = 1; i < ans.size(); ++i) {
        ans[i] = ans[i-1] - array[i-1] + array[i+k-1];
    }

    return ans;
}

int main(int argc, char** argv) {
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);

    int k = 3;
    vector<int> ans = sum_of_window(array, k);
    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans.at(i) << std::endl;
    }
}
