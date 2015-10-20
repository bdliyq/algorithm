#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/gas-station/

class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        # write your code here
        diff = [0 for i in xrange(len(gas))]
        total = 0
        for i in xrange(len(gas)):
            diff[i] = gas[i] - cost[i]
            total += diff[i]

        summary = 0
        index = 0
        for i in xrange(len(diff)):
            if summary < 0:
                summary = diff[i]
                index = i
            else:
                summary += diff[i]

        if total >= 0:
            return index
        return -1

if __name__ == '__main__':
    s = Solution()
    print s.canCompleteCircuit([1,1,3,1], [2,2,1,1])
