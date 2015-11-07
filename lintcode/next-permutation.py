#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/next-permutation/

class Solution:
    # @param num :  a list of integer
    # @return : a list of integer
    def nextPermutation(self, num):
        # write your code here
        if not num:
            return num

        for i in xrange(len(num)-2, -1, -1):
            if num[i+1] > num[i]:
                for j in xrange(len(num)-1, i-1, -1):
                    if num[j] > num[i]:
                        break
                num[i], num[j] = num[j], num[i]
                num[i+1:] = num[:i:-1]
                return num
        return num[::-1]

if __name__ == '__main__':
    s = Solution()
    print s.nextPermutation([1,3,2,3])
    print s.nextPermutation([1,6,5,4])
    print s.nextPermutation([4,3,2,1])


