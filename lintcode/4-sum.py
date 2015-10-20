#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/4-sum/

class Solution:
    def two_sum(self, numbers, except_index, target):
        low, high = 0, len(numbers)-1
        res = []
        while low < high:
            if low in except_index:
                low += 1
                continue
            if high in except_index:
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

    def three_sum(self, numbers, except_index, target):
        # write your code here
        res = []
        # numbers.sort()
        for i in xrange(len(numbers)):
            if i == except_index:
                continue

            two = self.two_sum(numbers, set([i, except_index]), target-numbers[i])
            if len(two) > 0:
                for two_res in two:
                    the_res = []
                    the_res.append(numbers[i])
                    the_res.extend(two_res)
                    res.append(sorted(the_res))

        return res

    def four_sum_without_hash(self, numbers, target):
        res = set()
        numbers.sort()
        for i in xrange(len(numbers)):
            three = self.three_sum(numbers, i, target-numbers[i])
            if len(three) > 0:
                for three_res in three:
                    the_res = []
                    the_res.append(numbers[i])
                    the_res.extend(three_res)
                    res.add(tuple(sorted(the_res)))

        return list(res)

    def four_sum_with_hash(self, numbers, target):
        two_sum_hash = {}
        numbers.sort()

        for i in xrange(0, len(numbers)):
            for j in xrange(i+1, len(numbers)):
                the_sum = numbers[i] + numbers[j]
                if two_sum_hash.has_key(the_sum):
                    two_sum_hash[the_sum].append([i, j])
                else:
                    two_sum_hash[the_sum] = [[i, j]]

        res = []
        for i in xrange(0, len(numbers) - 3):
            if i > 0 and numbers[i] == numbers[i-1]:
                continue
            for j in xrange(i+1, len(numbers) - 2):
                if j > i+1 and numbers[j] == numbers[j-1]:
                    continue
                diff = target - numbers[i] - numbers[j]
                if two_sum_hash.has_key(diff):
                    is_first_push = True
                    for first, second in two_sum_hash[diff]:
                        if first <= j:
                            continue
                        if is_first_push or res[-1][2] != numbers[first]:
                            res.append([numbers[i], numbers[j], numbers[first], numbers[second]])
                            is_first_push = False

        return res

    """
    @param numbersbers : Give an array numbersbersbers of n integer
    @param target : you need to find four elements that's sum of target
    @return : Find all unique quadruplets in the array which gives the sum of
              zero.
    """
    def fourSum(self, numbers, target):
        # write your code here
        # return self.four_sum_without_hash(numbers, target)
        return self.four_sum_with_hash(numbers, target)

if __name__ == '__main__':
    s = Solution()
    print s.fourSum([1,0,-1,-1,-1,-1,0,1,1,1,2], 2)
    # print s.fourSum([1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,0,0,-2,2,-5,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99], 11)
