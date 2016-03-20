// Question: Count-out.

class Solution {
public:
    vector<int> countout(int n, int k) {
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }

        int cur = 0;
        int p = 0;
        while (s.size() > n-k+1) {
            while (s.count(p) == 0) {
                p = (p+1) % n;
            }

            ++cur;
            if (cur == k) {
                s.erase(p);
                cur = 0;
            }

            p = (p+1) % n;
        }

        vector<int> ans;
        for (auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};
