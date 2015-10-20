#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/valid-parentheses/

class Solution:
    # @param {string} s A string
    # @return {boolean} whether the string is a valid parentheses
    def isValidParentheses(self, s):
        # Write your code here
        stack = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            else:
                if not stack:
                    return False
                if (stack[-1] == '(' and i != ')') or (stack[-1] == '[' and i != ']') or (stack[-1] == '{' and i != '}'):
                    return False
                stack.pop()
        if stack:
            return False
        return True


