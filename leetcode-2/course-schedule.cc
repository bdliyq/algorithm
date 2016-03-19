// Question: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in_degree(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto c : graph[cur]) {
                in_degree[c]--;
                if (in_degree[c] == 0) {
                    q.push(c);
                }
            }
        }

        return count(in_degree.begin(), in_degree.end(), 0) == in_degree.size();
    }
};
