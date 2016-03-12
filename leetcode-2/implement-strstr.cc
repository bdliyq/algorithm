// Question: https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = -1;
        int len1 = haystack.size(), len2 = needle.size();
        while (i < len1-len2) {
            int j = i+1;
            int k = 0;
            while (j < len1 && k < len2 && haystack[j] == needle[k]) {
                ++j;
                ++k;
            }
            if (k == len2) {
                return i+1;
            }
            ++i;
        }
        return -1;
    }
};
