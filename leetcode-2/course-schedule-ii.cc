// Question: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in_degree(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }

        vector<int> ans(numCourses, -1);
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        int idx = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto c : graph[cur]) {
                in_degree[c]--;
                if (in_degree[c] == 0) {
                    q.push(c);
                }
            }
            ans[idx++] = cur;
        }

        if (idx == numCourses) {
            return ans;
        }
        return vector<int>();
    }
};
