// Question: Arithmetic sequence.

#include <vector>
#include <iostream>
using namespace std;

int arithmetic_sequence(vector<int> array) {
    if (array.size() < 3) {
        return 0;
    }

    int ans = 0;
    int gap = array[1] - array[0];
    int len = 2;

    for (size_t i = 1; i < array.size()-1; ++i) {
        if (array[i+1] - array[i] == gap) {
            ++len;
        } else {
            gap = array[i+1] - array[i];
            if (len >= 3) {
                ans += (len-1) * (len-2) / 2;
                len = 2;
            }
            if (ans > 1000000000) {
                return -1;
            }
        }
    }

    if (len >= 3) {
        ans += (len-1) * (len-2) / 2;
    }

    return ans > 1000000000 ? -1 : ans;
}

int main(int argc, char** argv) {
    vector<int> array;
    array.push_back(-1);
    array.push_back(1);
    array.push_back(3);
    array.push_back(3);
    array.push_back(3);
    array.push_back(2);
    array.push_back(1);
    array.push_back(0);

    cout << arithmetic_sequence(array) << endl;
}
