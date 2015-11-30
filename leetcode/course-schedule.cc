// Question: https://leetcode.com/problems/course-schedule/

#include "headers.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto p : prerequisites) {
            adj[p.first].push_back(p.second);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onstack(numCourses, false);
        bool has_cycle = false;
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, onstack, has_cycle);
            }
        }
        return !has_cycle;
    }

private:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& onstack, bool& has_cycle) {
        visited[v] = true;
        onstack[v] = true;
        for (auto w : adj[v]) {
            if (has_cycle) {
                return;
            } else if (!visited[w]) {
                dfs(w, adj, visited, onstack, has_cycle);
            } else if (onstack[w]) {
                has_cycle = true;
                return;
            }
        }
        onstack[v] = false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<pair<int,int>> prerequisites;
    prerequisites.push_back(make_pair(0,1));
    prerequisites.push_back(make_pair(1,0));
    cout << s.canFinish(2, prerequisites) << endl;
}
