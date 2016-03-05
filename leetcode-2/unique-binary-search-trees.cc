// Question: https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }

        if (memos.count(n) != 0) {
            return memos[n];
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += numTrees(i-1) * numTrees(n-i);
        }
        memos[n] = ans;
        return ans;
    }

private:
    unordered_map<int, int> memos;
};
