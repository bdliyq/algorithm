// Question: https://leetcode.com/problems/nim-game/

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3) {
            return true;
        }

        return n % 4 != 0;
    }

private:
    unordered_map<int, bool> memo_;
};
