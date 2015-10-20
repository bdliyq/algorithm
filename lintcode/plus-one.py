#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/plus-one/

class Solution:
    # @param {int[]} digits a number represented as an array of digits
    # @return {int[]} the result
    def plusOne(self, digits):
        # Write your code here
        stack = []
        carry = 0
        for i in xrange(len(digits)-1, -1, -1):
            if i == len(digits)-1:
                stack.append((digits[i]+1) % 10)
                carry = (digits[i]+1) / 10
            else:
                stack.append((carry+digits[i]) % 10)
                carry = (carry+digits[i]) / 10
        if carry > 0:
            stack.append(carry)
        res = []
        while stack:
            res.append(stack.pop())
        return res

if __name__ == '__main__':
    s = Solution()
    print s.plusOne([8,9,9])
    print s.plusOne([9,9,9])
    print s.plusOne([1,2,3])
