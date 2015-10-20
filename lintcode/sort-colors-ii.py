#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sort-colors-ii/

class Solution:
    def sort_colors(self, colors, start_pos, end_pos, start_k, end_k):
        if start_pos >= end_pos or start_k >= end_k:
            return

        p = start_pos
        q = end_pos
        r = p
        k = (start_k + end_k) / 2
        while r <= q:
            if colors[r] < k:
                colors[r], colors[p] = colors[p], colors[r]
                while p <= end_pos and colors[p] < k:
                    p += 1
                if r < p:
                    r = p
            elif colors[r] == k:
                r += 1
            else:  # color[r] > k
                colors[r], colors[q] = colors[q], colors[r]
                while q >= start_pos and colors[q] > k:
                    q -= 1

        self.sort_colors(colors, start_pos, p - 1, start_k, k - 1)
        self.sort_colors(colors, r, end_pos, k + 1, end_k)

    """
    @param colors: A list of integer
    @param k: An integer
    @return: nothing
    """
    def sortColors2(self, colors, k):
        # write your code here
        self.sort_colors(colors, 0, len(colors) - 1, 1, k)

if __name__ == '__main__':
    s = Solution()
    array = [3, 2, 2, 1, 4]
    s.sortColors2(array, 4)
    print array

