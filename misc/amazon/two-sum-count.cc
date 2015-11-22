// Question: Two sum count.

#include <vector>
#include <map>
#include <iostream>
using namespace std;

int two_sum_count(vector<int> array, int target) {
    map<int, int> m;
    int ans = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        if (m.count(target-array[i]) != 0) {
            ans += m[target-array[i]];
        }

        if (m.count(array[i]) == 0) {
            m[array[i]] = 1;
        } else {
            ++m[array[i]];
        }
    }

    return ans;
}

int main(int argc, char** argv) {
    vector<int> array;
    array.push_back(1);
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    int target = 5;
    cout << two_sum_count(array, target) << endl;
}
