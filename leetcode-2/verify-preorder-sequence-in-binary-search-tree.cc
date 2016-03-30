// Question:
// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//
// You may assume each number in the sequence is unique.
//
// Follow up:
// Could you do it using only constant space complexity?

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
    }

    bool helper(vector<int>& preorder, int start, int end) {
        if (start + 1 >= end) {
            return true;
        }

        int root = preorder[start];
        int i = start + 1;
        while (i < end && preorder[i] < root) {
            ++i;
        }

        if (i == end) {
            return helper(preorder, start+1, end);
        } else {
            int j = i;
            while (j < end) {
                if (preorder[j] < root) {
                    return false;
                }
                ++j;
            }
            return helper(preorder, start+1, i) && helper(preorder, i, end);
        }
    }
};
