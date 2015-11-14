#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/valid-number/

class Solution:
    # @param {string} s the string that represents a number
    # @return {boolean} whether the string is a valid number
    def isNumber(self, s):
        # Write your code here
        start = 0
        while start < len(s) and s[start] == ' ':
            start += 1
        if start < len(s) and (s[start] == '-' or s[start] == '+'):
            start += 1
        end = start
        while end < len(s) and s[end] >= '0' and s[end] <= '9':
            end += 1
        n1 = end - start

        start = end
        if start < len(s) and s[start] == '.':
            start += 1
        end = start
        while end < len(s) and s[end] >= '0' and s[end] <= '9':
            end += 1
        n2 = end - start

        if n1 + n2 == 0:
            return False

        start = end
        if start < len(s) and (s[start] == 'e' or s[start] == 'E'):
            start += 1
            if start < len(s) and (s[start] == '-' or s[start] == '+'):
                start += 1
            end = start
            while end < len(s) and s[end] >= '0' and s[end] <= '9':
                end += 1
            n3 = end - start
            if n3 == 0:
                return False

        start = end
        while start < len(s) and s[start] == ' ':
            start += 1
        return start == len(s)
