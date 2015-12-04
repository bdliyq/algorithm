// Question: https://leetcode.com/problems/gas-station/

#include "headers.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += (gas[i] - cost[i]);
        }
        if (total < 0) {
            return -1;
        }

        int ans = 0;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (sum < 0) {
                ans = i;
                sum = 0;
            }
            sum += (gas[i] - cost[i]);
        }
        return ans;
    }
};
