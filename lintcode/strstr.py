#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/strstr/

class Solution:
    def strStr(self, source, target):
        # write your code here
        if source is None or target is None:
            return -1
        if len(source) == 0 and len(target) > 0:
            return -1

        s = -1
        p = -1
        q = -1
        while s < len(source):
            while p+1 < len(source) and q+1 < len(target) and source[p+1] == target[q+1]:
                p += 1
                q += 1
            if q == len(target) - 1:
                return s + 1
            else:
                s += 1
                p = s
                q = -1

        return -1

if __name__ == '__main__':
    s = Solution()
    print s.strStr('', '')
    print s.strStr('abc', '')
    print s.strStr('abc', 'b')
    print s.strStr('', 'abc')
    print s.strStr('source', 'target')
    print s.strStr('abcdabcdefg', 'bcd')
    print s.strStr('bcdabcdefg', 'bcd')
    print s.strStr('cdabdefgbcd', 'bcd')
