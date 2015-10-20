#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/ugly-number/

class Solution:
    """
    @param k: The number k.
    @return: The kth prime number as description.
    """
    def kthPrimeNumber(self, k):
        # write your code here
        res = [1]
        k3, k5, k7 = 0, 0, 0
        for i in xrange(1, k+1):
            res.append(min(res[k3] * 3, res[k5] * 5, res[k7] * 7))
            if res[-1] % 3 == 0:
                k3 += 1
            if res[-1] % 5 == 0:
                k5 += 1
            if res[-1] % 7 == 0:
                k7 += 1
        return res[-1]

if __name__ == '__main__':
    s = Solution()
    print s.kthPrimeNumber(4)
