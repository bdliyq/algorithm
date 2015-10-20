#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/add-binary/

class Solution:
    # @param {string} a a number
    # @param {string} b a number
    # @return {string} the result
    def addBinary(self, a, b):
        # Write your code here
        if len(a) == 0:
            return b
        if len(b) == 0:
            return a

        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        result = ''
        while i >= 0 or j >= 0:
            ia = 0
            ib = 0
            if i >= 0:
                ia = int(a[i])
            if j >= 0:
                ib = int(b[j])
            ic = (ia + ib + carry) % 2
            carry = (ia + ib + carry) / 2
            result = str(ic) + result
            i -= 1
            j -= 1
        if carry > 0:
            result = str(carry) + result

        return result

if __name__ == '__main__':
    s = Solution()
    print s.addBinary('11', '1')
