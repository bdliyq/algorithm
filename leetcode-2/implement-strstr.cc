// Question: https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        while (i <= (int)haystack.size() - (int)needle.size()) {
            int j = 0;
            while (i+j < haystack.size() && j < needle.size() && haystack[i+j] == needle[j]) {
                ++j;
            }
            if (j == needle.size()) {
                return i;
            }
            ++i;
        }
        return -1;
    }
};
