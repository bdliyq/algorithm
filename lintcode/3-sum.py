#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/3-sum/

class Solution:
    def two_sum(self, numbers, except_index, target):
        low, high = 0, len(numbers)-1
        res = []
        while low < high:
            if low == except_index:
                low += 1
                continue
            if high == except_index:
                high -= 1
                continue

            the_sum = numbers[low] + numbers[high]
            if the_sum == target:
                res.append([numbers[low], numbers[high]])
                low += 1
                high -= 1
            elif the_sum > target:
                high -= 1
            else:
                low += 1
        return res

    """
    @param numbersbers : Give an array numbersbers of n integer
    @return : Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        # write your code here
        res = set()
        numbers.sort()
        for i in xrange(len(numbers)):
            two = self.two_sum(numbers, i, 0-numbers[i])
            if len(two) > 0:
                for two_res in two:
                    the_res = []
                    the_res.append(numbers[i])
                    the_res.extend(two_res)
                    res.add(tuple(sorted(the_res)))

        return list(res)

if __name__ == '__main__':
    s = Solution()
    print s.threeSum([-1,0,1,2,-1,-4])
