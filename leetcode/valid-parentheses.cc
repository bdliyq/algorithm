// Question: https://leetcode.com/problems/valid-parentheses/

#include "headers.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0) {
                st.push(s[i]);
            } else {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    st.push(s[i]);
                } else {
                    if (s[i] == ')' && (st.empty() || st.top() != '(') ||
                            s[i] == ']' && (st.empty() || st.top() != '[') ||
                            s[i] == '}' && (st.empty() || st.top() != '{')) {
                        return false;
                    }
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};

int main(int argc, char** argv) {
    return 0;
}
