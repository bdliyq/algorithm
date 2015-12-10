// Question: https://leetcode.com/problems/candy/

#include "headers.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        if (ratings.empty()) {
            return ans;
        }

        int len = ratings.size();
        vector<int> traverse(len, 1);
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i-1]) {
                traverse[i] = traverse[i-1] + 1;
            }
        }

        vector<int> reverse(len, 1);
        for (int i = len-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                reverse[i] = reverse[i+1] + 1;
            }
        }

        for (int i = 0; i < len; ++i) {
            ans += max(traverse[i], reverse[i]);
        }

        return ans;

        // for (int i = 1; i < len; ++i) {
        //     if (ratings[i] > ratings[i-1]) {
        //         candies[i] = candies[i-1] + 1;
        //     }

        //     for (int j = i-1; j >= 0; --j) {
        //         if (ratings[j] > ratings[j+1]) {
        //             if (candies[j] <= candies[j+1]) {
        //                 candies[j] = candies[j+1] + 1;
        //             }
        //         } else {
        //             break;
        //         }
        //     }
        // }

        // for (auto c : candies) {
        //     ans += c;
        // }

        // return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> ratings{8,2,3,5,6,7,4,2,1,9};
    cout << s.candy(ratings) << endl;
    return 0;
}
