// Question: GCD

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solution(vector<int> array) {
    if (array.empty()) {
        return 0;
    }

    int ans = array[0];
    for (size_t i = 0; i < array.size(); ++i) {
        ans = gcd(ans, array.at(i));
    }

    return ans;
}

int main(int argc, char** argv) {
    vector<int> array;
    array.push_back(123456);
    array.push_back(7890);
    array.push_back(12);
    array.push_back(24);
    array.push_back(60);

    std::cout << solution(array) << std::endl;
}
