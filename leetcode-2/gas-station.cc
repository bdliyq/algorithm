// Question: https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = gas.size();
        int total = 0;
        for (int i = 0; i < count; ++i) {
            total += (gas[i] - cost[i]);
        }
        if (total < 0) {
            return -1;
        }

        int ans = 0;
        int sum = 0;
        for (int i = 0; i < count; ++i) {
            if (sum < 0) {
                ans = i;
                sum = 0;
            }
            sum += (gas[i] - cost[i]);
        }
        return ans;
    }
};
