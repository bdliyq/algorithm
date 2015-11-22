// Question: Is valid parentheses.

#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool is_valid_parentheses(string& s) {
    if (s.size() < 2) {
        return false;
    }

    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i) {
        if (st.empty()) {
            st.push(s[i]);
        } else if (s[i] - st.top() == 1 || s[i] - st.top() == 2) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main(int argc, char** argv) {
    string s1 = "()[]{}";
    string s2 = "([{}])";
    string s3 = "([{]])";

    cout << is_valid_parentheses(s1) << endl;
    cout << is_valid_parentheses(s2) << endl;
    cout << is_valid_parentheses(s3) << endl;
}
