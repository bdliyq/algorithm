#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/heapify/

class Solution:
    def min_heapify_with_recursion(self, array, index, heap_size):
        if index >= heap_size:
            return

        index_min = index
        index_left = index * 2 + 1
        index_right = index * 2 + 2

        if index_left < heap_size and array[index_left] < array[index_min]:
            index_min = index_left
        if index_right < heap_size and array[index_right] < array[index_min]:
            index_min = index_right

        if index_min == index:
            return

        array[index_min], array[index] = array[index], array[index_min]
        self.min_heapify_with_recursion(array, index_min, heap_size)

    def min_heapify_with_no_recursion(self, array, index, heap_size):
        if index >= heap_size:
            return

        while True:
            index_min = index
            index_left = index * 2 + 1
            index_right = index * 2 + 2

            if index_left < heap_size and array[index_left] < array[index_min]:
                index_min = index_left
            if index_right < heap_size and array[index_right] < array[index_min]:
                index_min = index_right

            if index_min == index:
                break

            array[index_min], array[index] = array[index], array[index_min]
            index = index_min

    def min_heap_sort(self, array):
        self.heapify(array)

        for i in xrange(len(array) - 1, -1, -1):
            array[i], array[0] = array[0], array[i]
            self.min_heapify_with_no_recursion(array, 0, i)

    # @param A: Given an integer array
    # @return: void
    def heapify(self, A):
        # write your code here
        middle = len(A) / 2
        for i in xrange(middle, -1, -1):
            self.min_heapify_with_no_recursion(A, i, len(A))

if __name__ == '__main__':
    s = Solution()
    array = [45,39,32,11]
    s.heapify(array)
    print array
    s.min_heap_sort(array)
    print array
