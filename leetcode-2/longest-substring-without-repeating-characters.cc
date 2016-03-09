// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include "headers.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int i = 0, j = 0, len = s.size(), ans = INT_MIN;
        while (j < len) {
            auto c = s[j];
            if (m.count(c) == 0) {
                m.insert(c);
            } else {
                ans = max(ans, j-i);
                while (i <= j && s[i] != c) {
                    m.erase(s[i]);
                    ++i;
                }
                ++i;
            }
            ++j;
        }
        return max(ans, j-i);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.lengthOfLongestSubstring("aaaa") << endl;
    cout << s.lengthOfLongestSubstring("abcd") << endl;
}
