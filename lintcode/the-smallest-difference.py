#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/the-smallest-difference/

class Solution:
    # @param A, B: Two lists of integer
    # @return: An integer
    def smallestDifference(self, A, B):
        # write your code here
        A.sort()
        res = None
        for x in B:
            low = 0
            high = len(A) - 1
            min_diff = None
            while low <= high:
                mid = (low + high) / 2
                diff = x - A[mid]
                if diff == 0:
                    return 0

                if diff > 0:
                    low = mid + 1
                else:
                    high = mid - 1

                if not min_diff:
                    min_diff = abs(diff)
                else:
                    min_diff = min(min_diff, abs(diff))

            if not res:
                res = min_diff
            else:
                res = min(res, min_diff)
        return res

if __name__ == '__main__':
    s = Solution()
    # print s.smallestDifference([3,6,7,4], [2,8,9,3])
    # print s.smallestDifference([1,5,6,7], [-8,3,4,9])
    print s.smallestDifference([27787,35761,66682,79896,55399,40996,30827,2586,71163,52816,18222,60534,14108,48743,33563,30627,76976,58764,75618,33403,59769,73382,51892,70283,55157,67299,58957,52318,64273,51299,63167,38929,39255,58742,82391,72508,65052,36890,11934,64099,72048,63847,37472,72041,41944,12821,81958,68987,17813,15311,53853,33451,65412,25747,49166,27766,22905,60321,62836,28171,45495,79595,46793,62237,62449,61418,65665,75405,45804,52812,11232,31589,55168,42575,38718,47001,82005,32121,72787,74600,25153,47440,1298,13449], [3835,4542,1154,5449,7974,6680,6296,4410,5797,5114,4590,1690,295,831,3315,7252,3643,2408,6163,7142,2436,1026,8395,7350,7642,3130,3744,5217])





