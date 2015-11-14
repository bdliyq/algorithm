#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/roman-to-integer/

class Solution:
    # @param {string} s Roman representation
    # @return {int} an integer
    def romanToInt(self, s):
        # Write your code here
        if not s:
            return 0

        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        ans = 0
        sub = roman[s[0]]
        lastv = sub

        for c in s[1:]:
            curv = roman[c]
            if curv == lastv:
                sub += curv
            elif curv < lastv:
                ans += sub
                sub = curv
            else:
                sub = curv - sub
            lastv = curv

        ans += sub
        return ans


