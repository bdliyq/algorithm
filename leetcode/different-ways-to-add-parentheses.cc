// Question: https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) {
            return vector<int>();
        }
        vector<int> ans;
        bool pure_num = true;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] < '0' || input[i] > '9') {
                pure_num = false;
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (auto l : left) {
                    for (auto r : right) {
                        if (input[i] == '-') {
                            ans.push_back(l - r);
                        } else if (input[i] == '+') {
                            ans.push_back(l + r);
                        } else if (input[i] == '*') {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }
        if (pure_num) {
            ans.push_back(atoi(input.c_str()));
        }
        return ans;
    }
};

int main(int arg, char** argv) {
    Solution s;
    vector<int> ans = s.diffWaysToCompute("2*3-4*5");
    for (auto a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
