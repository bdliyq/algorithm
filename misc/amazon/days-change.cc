// Question: Days change.

#include <vector>
#include <iostream>
using namespace std;

vector<int> days_change(vector<int> cells, int k) {
    if (cells.empty() || k <= 0) {
        return cells;
    }

    vector<int> ans(cells.size()+2, 0);
    for (size_t i = 0; i < cells.size(); ++i) {
        ans[i+1] = cells[i];
    }

    int pre = ans[0];
    for (size_t i = 0; i < (size_t)k; ++i) {
        for (size_t j = 1; j < ans.size()-1; ++j) {
            int t = ans[j];
            ans[j] = pre ^ ans[j+1];
            pre = t;
        }
    }

    return vector<int>(ans.begin()+1, ans.end()-1);
}

int main(int argc, char** argv) {
    vector<int> cells;
    cells.push_back(1);
    cells.push_back(0);
    cells.push_back(0);
    cells.push_back(0);
    cells.push_back(0);
    cells.push_back(1);
    cells.push_back(0);
    cells.push_back(0);

    int k = 1;
    vector<int> ans = days_change(cells, k);
    for (size_t i = 0 ; i < ans.size(); ++i) {
        cout << ans.at(i) << endl;
    }
}
