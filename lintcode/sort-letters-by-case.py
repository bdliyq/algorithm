#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sort-letters-by-case/

class Solution:
    """
    @param chars: The letters array you should sort.
    """
    def sortLetters(self, chars):
        # write your code here
        i = 0
        j = 0
        while i < len(chars):
            if chars[i] <= 'z' and chars[i] >= 'a':
                chars[i], chars[j] = chars[j], chars[i]
                j += 1
            i += 1

if __name__ == '__main__':
    s = Solution()
    chars = list('abAcD')
    s.sortLetters(chars)
    print chars


