// Question: https://leetcode.com/problems/maximum-product-of-word-lengths/

#include "headers.h"

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<int> dicts(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) {
                dicts[i] |= (1 << (c - 'a'));
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (dicts[i] & dicts[j]) {
                    continue;
                }
                ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<string> words{"abc", "a", "b", ""};
        cout << s.maxProduct(words) << endl;
    }
    {
        vector<string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        cout << s.maxProduct(words) << endl;
    }
    {
        vector<string> words{"a", "aa", "aaa", "aaaa"};
        cout << s.maxProduct(words) << endl;
    }
    return 0;
}
