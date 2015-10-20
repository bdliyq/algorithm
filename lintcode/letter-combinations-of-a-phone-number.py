#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/letter-combinations-of-a-phone-number/

class Solution:
    def get_button_dict(self):
        button_dict = {}
        button_dict['2'] = 'abc'
        button_dict['3'] = 'def'
        button_dict['4'] = 'ghi'
        button_dict['5'] = 'jkl'
        button_dict['6'] = 'mno'
        button_dict['7'] = 'pqrs'
        button_dict['8'] = 'tuv'
        button_dict['9'] = 'wxyz'
        return button_dict

    def work_with_recursion(self, digits, prefix, result, button_dict):
        if len(digits) == 0:
            result.extend(prefix)
            return

        button = digits[0]
        if button_dict.has_key(button):
            button_string = button_dict[button]
            new_prefix = []
            for c in button_string:
                if len(prefix) > 0:
                    for s in prefix:
                        new_prefix.append(s + c)
                else:
                    new_prefix.append(c)
            self.work_with_recursion(digits[1:], new_prefix, result, button_dict)
        else:
            self.work_with_recursion(digits[1:], prefix, result, button_dict)


    # @param {string} digits A digital string
    # @return {string[]} all posible letter combinations
    def letterCombinations(self, digits):
        # Write your code here
        button_dict = self.get_button_dict()
        result = []
        self.work_with_recursion(digits, [], result, button_dict)
        return sorted(result)

if __name__ == '__main__':
    s = Solution()
    print s.letterCombinations('123')
    print s.letterCombinations('223')
    print s.letterCombinations('23')
    print s.letterCombinations('2')
    print s.letterCombinations('')
