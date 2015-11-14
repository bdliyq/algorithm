#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/integer-to-roman/

class Solution:
    # @param {int} n The integer
    # @return {string} Roman representation
    def intToRoman(self, n):
        # Write your code here
        symbol = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        value = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        ans = []
        i = 0
        while n != 0:
            if n >= value[i]:
                n -= value[i]
                ans.append(symbol[i])
            else:
                i += 1
        return ''.join(ans)
