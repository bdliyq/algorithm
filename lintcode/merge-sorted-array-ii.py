#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/merge-sorted-array-ii/

class Solution:
    def find(self, array, start, end, x):
        low = start
        high = end
        while low < high:
            mid = (low + high) / 2
            if array[mid] == x:
                k = mid + 1
                while k <= high and array[k-1] == array[k]:
                    k += 1
                return k
            elif array[mid] < x:
                low = mid + 1
            else:
                high = mid - 1

        if array[low] <= x:
            return low + 1
        else:
            return low

    #@param A and B: sorted integer array A and B.
    #@return: A new sorted integer array
    def mergeSortedArray(self, A, B):
        # write your code here
        if len(A) == 0:
            return B
        if len(B) == 0:
            return A
        if len(A) > len(B):
            A, B = B, A

        result = []
        i = 0
        while i < len(A) and len(B) > 0:
            n = A[i]
            k = i + 1
            while k < len(A) and A[k-1] == A[k]:
                k += 1

            pos = self.find(B, 0, len(B) - 1, n)
            if pos == 0:
                result.extend(A[i:k])
                i = k
            elif pos <= len(B):
                result.extend(B[:pos])
                result.extend(A[i:k])
                i = k
                B = B[pos:]

        if i < len(A):
            result.extend(A[i:])
        elif len(B) > 0:
            result.extend(B)

        return result

if __name__ == '__main__':
    arr1 = [1,3,5]
    arr2 = [4]
    s = Solution()
    print s.mergeSortedArray(arr1, arr2)
    # print s.find([1,3,3,4,5,6], 0, 5, 100)
