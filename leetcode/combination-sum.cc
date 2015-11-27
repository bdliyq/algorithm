// Question: https://leetcode.com/problems/combination-sum/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int> > ans;

        helper(candidates, path, ans, target, 0);
        return ans;
    }

private:
    void helper(vector<int>& candidates, vector<int>& path, vector<vector<int> >& ans, int target, int cursor) {
        if (target == 0) {
            if (!path.empty()) {
                ans.push_back(path);
            }
        } else if (target > 0) {
            for (int i = cursor; i < candidates.size(); ++i) {
                if (i > cursor && candidates.at(i) == candidates.at(i-1)) {
                    continue;
                }
                path.push_back(candidates.at(i));
                helper(candidates, path, ans, target - candidates.at(i), i);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char** argv) {
    int cs[] = {2,2,2,3,6,7};
    vector<int> candidates(cs, cs+sizeof(cs)/sizeof(int));
    Solution s;
    vector<vector<int> > ans = s.combinationSum(candidates, 7);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans.at(i).size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
