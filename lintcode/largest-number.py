#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/largest-number/

class Solution:
    #@param num: A list of non negative integers
    #@return: A string
    def largestNumber(self, num):
        # write your code here
        numbers = []
        for n in num:
            numbers.append(str(n))
        numbers.sort(cmp = lambda x,y:cmp(x+y, y+x))
        res = ''.join(numbers[::-1])
        if res.count('0') == len(res):
            res = '0'
        return res

if __name__ == '__main__':
    s = Solution()
    print s. largestNumber([9,99,98])
