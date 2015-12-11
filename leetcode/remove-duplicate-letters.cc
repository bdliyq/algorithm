// Question: https://leetcode.com/problems/remove-duplicate-letters/

#include "headers.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char, int> dict;
        unordered_set<char> visited;
        for (char c : s) { ++dict[c]; }

        for (char c : s) {
            if (visited.count(c) == 0) {
                while (!st.empty() && c <= st.top() && dict[st.top()] > 0) {
                    visited.erase(st.top());
                    st.pop();
                }
                st.push(c);
                visited.insert(c);
            }
            --dict[c];
        }

        stringstream ss;
        while (!st.empty()) {
            ss << st.top();
            st.pop();
        }
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.removeDuplicateLetters("bbcaac") << endl;
}
