// Question: https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multimap<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m.insert(make_pair(nums[i], i));
        }

        auto p1 = m.begin();
        while (p1 != m.end()) {
            auto p2 = p1;
            ++p2;
            while (p2 != m.end() && (long)p2->first - (long)p1->first <= (long)t) {
                if (abs(p2->second - p1->second) <= k) {
                    return true;
                }
                ++p2;
            }
            ++p1;
        }
        return false;
    }
};
