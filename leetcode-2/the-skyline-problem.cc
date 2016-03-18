// Question: https://leetcode.com/problems/the-skyline-problem/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> bldgs;
        for (auto& b : buildings) {
            bldgs.push_back({b[0], -b[2]});
            bldgs.push_back({b[1], b[2]});
        }
        sort(bldgs.begin(), bldgs.end());

        int prev = 0, curr = 0;
        multiset<int> m;
        m.insert(0);
        vector<pair<int, int>> ans;
        for (auto& b : bldgs) {
            if (b.second < 0) {
                m.insert(-b.second);
            } else {
                m.erase(m.find(b.second));
            }
            curr = *m.rbegin();
            if (prev != curr) {
                ans.push_back({b.first, curr});
                prev = curr;
            }
        }
        return ans;
    }
};
