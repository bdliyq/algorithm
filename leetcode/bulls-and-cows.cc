// Question: https://leetcode.com/problems/bulls-and-cows/

#include "headers.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        string ns(""), ng("");
        unordered_map<char, int> m;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bull;
            } else {
                ns += secret.substr(i, 1);
                ng += guess.substr(i, 1);
                ++m[secret[i]];
            }
        }

        int cow = 0;
        for (int i = 0; i < ng.size(); ++i) {
            if (m.count(ng[i]) > 0) {
                ++cow;
                --m[ng[i]];
                if (m[ng[i]] == 0) {
                    m.erase(ng[i]);
                }
            }
        }
        stringstream ss;
        ss << bull << "A" << cow << "B";
        return ss.str();
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.getHint("011", "110") << endl;
    return 0;
}
