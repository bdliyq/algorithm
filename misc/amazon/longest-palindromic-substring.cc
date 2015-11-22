// Question: Longest palindromic substring.

#include <string>
#include <iostream>
using namespace std;

string longest_palindromic_substring(string s) {
    if (s.empty()) {
        return "";
    }

    string ans = s.substr(0, 1);

    for (int i = 0; i < s.size(); ++i) {
        int j = 0;
        while (i-j >= 0 && i-j < s.size() && s[i-j] == s[i+j]) {
            ++j;
        }
        if (2*j-1 > ans.size()) {
            ans = s.substr(i-j+1, 2*j-1);
        }
    }

    for (int i = 0; i < s.size(); ++i) {
        int j = 0;
        while (i-j >= 0 && i+j+1 < s.size() && s[i-j] == s[i+j+1]) {
            ++j;
        }
        if (2*j > ans.size()) {
            ans = s.substr(i-j+1, 2*j);
        }
    }

    return ans;
}

int main(int argc, char** argv) {
    cout << longest_palindromic_substring("abcdzdcab") << endl;
    cout << longest_palindromic_substring("abcddcab") << endl;
    cout << longest_palindromic_substring("abcd") << endl;
}
