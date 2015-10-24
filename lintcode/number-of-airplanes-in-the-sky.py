#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/number-of-airplanes-in-the-sky/

"""
Definition of Interval.
"""
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    def work_with_hashtable(self, airplanes):
        count = {}
        for ap in airplanes:
            for i in xrange(ap.start, ap.end):
                if count.has_key(i):
                    count[i] += 1
                else:
                    count[i] = 1
        res = 0
        for k,v in count.items():
            res = max(res, v)
        return res

    def work_with_another_way(self, airplanes):
        departure = []
        landing = []
        for ap in airplanes:
            departure.append(ap.start)
            landing.append(ap.end)
        departure.sort()
        landing.sort()

        air_in_sky = 0
        max_air_in_sky = 0
        i = 0
        j = 0
        while i < len(departure) and j < len(landing):
            if departure[i] < landing[j]:
                i += 1
                air_in_sky += 1
                max_air_in_sky = max(max_air_in_sky, air_in_sky)
            else:
                j += 1
                air_in_sky -= 1

        return max_air_in_sky

    # @param airplanes, a list of Interval
    # @return an integer
    def countOfAirplanes(self, airplanes):
        # write your code here
        return self.work_with_another_way(airplanes)

if __name__ == '__main__':
    s = Solution()
    print s.countOfAirplanes([Interval(1,10), Interval(2,3), Interval(5,8), Interval(4,7)])

