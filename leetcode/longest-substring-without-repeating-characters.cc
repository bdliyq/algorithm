// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int ans = 1;
        set<char> hs;
        hs.insert(s.at(0));
        int j = 0;
        int i = 1;
        for (i = 1; i < s.size(); ++i) {
            if (hs.count(s.at(i)) > 0) {
                ans = max(ans, i-j);
                while (j < i) {
                    if (s.at(j) == s.at(i)) {
                        ++j;
                        break;
                    }
                    hs.erase(hs.find(s.at(j)));
                    ++j;
                }
            } else {
                hs.insert(s.at(i));
            }
        }
        return max(ans, i-j);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.lengthOfLongestSubstring("c") << endl;
    cout << s.lengthOfLongestSubstring("cd") << endl;
    cout << s.lengthOfLongestSubstring("abccd") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
}
