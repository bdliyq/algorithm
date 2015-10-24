#!/usr/bin/env python
# encoding: utf-8

# Quesiont: https://leetcode.com/problems/implement-strstr/

import sys
class Solution(object):
    def work_with_normal(self, haystack, needle):
        if len(needle) == 0:
            return 0

        if len(haystack) == 0 or len(needle) > len(haystack):
            return -1

        for i in xrange(len(haystack) - len(needle) + 1):
            j = 0
            while j < len(needle):
                if haystack[i+j] != needle[j]:
                    break
                j += 1
            if j == len(needle):
                return i
            i += 1
        return -1

    def helper_preprocess(self, lps, needle):
        lps[0] = 0
        j = 0
        i = 1
        while i < len(needle):
            if needle[i] == needle[j]:
                j += 1
                lps[i] = j
                i += 1
            else:
                if j != 0:
                    j = lps[j-1]
                else:
                    lps[i] = 0
                    i += 1

    def work_with_kmp(self, haystack, needle):
        if len(needle) == 0:
            return 0

        if len(haystack) == 0 or len(haystack) < len(needle):
            return -1

        lps = [sys.maxint for i in xrange(len(needle))]
        self.helper_preprocess(lps, needle)

        i = 0
        j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            if j == len(needle):
                # j = lps[j-1]
                return i-j
            elif i < len(haystack) and haystack[i] != needle[j]:
                if j != 0:
                    j = lps[j-1]
                else:
                    i += 1
        return -1

    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        # return self.work_with_normal(haystack, needle)
        return self.work_with_kmp(haystack, needle)

if __name__ == '__main__':
    s = Solution()
    print s.strStr('aabcddefg', 'abcdd')
    print s.strStr('abcdefg', 'bcdf')
