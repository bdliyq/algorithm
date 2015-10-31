#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/majority-number-iii/

class Solution:
    """
    @param nums: A list of integers
    @param k: As described
    @return: The majority number
    """
    def majorityNumber(self, nums, k):
        # write your code here
        candidate_dict = {}
        for n in nums:
            if candidate_dict.has_key(n):
                candidate_dict[n] += 1
            else:
                candidate_dict[n] = 1
                if len(candidate_dict) == k:
                    for p, q in candidate_dict.items():
                        candidate_dict[p] -= 1
                        if candidate_dict[p] == 0:
                            del candidate_dict[p]

        for p, q in candidate_dict.items():
            candidate_dict[p] = 0

        for n in nums:
            if candidate_dict.has_key(n):
                candidate_dict[n] += 1

        ans = 0
        max_count = 0
        for p, q in candidate_dict.items():
            if max_count < q:
                max_count = q
                ans = p

        return ans
