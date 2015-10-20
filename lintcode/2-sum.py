#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/2-sum/

class Solution:
    """
    @param numbers : An array of Integer
    @param target : target = numbers[index1] + numbers[index2]
    @return : [index1 + 1, index2 + 1] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        # write your code here
        numbers_copy = []
        for i in xrange(len(numbers)):
            numbers_copy.append((numbers[i], i+1))

        numbers_copy = sorted(numbers_copy, key=lambda x:x[0])
        # numbers_copy = sorted(numbers_copy, cmp=lambda x,y:cmp(x[0],y[0]))

        low = 0
        high = len(numbers) - 1
        while low < high:
            the_sum = numbers_copy[low][0] + numbers_copy[high][0]
            if the_sum - target > 0:
                high -= 1
            elif the_sum - target == 0:
                return sorted([numbers_copy[low][1], numbers_copy[high][1]])
            else:
                low += 1

if __name__ == '__main__':
    s = Solution()
    print s.twoSum([2,7,11,15], 9)
    print s.twoSum([1,0,-1], -1)
