// Question: Given an input array of integers of size n, and a query array of integers of size k, find the smallest window of input array that contains all the elements of query array and also in the same order.
// Example: input is { 2, 5, 2, 8, 0, 1, 4, 7 }, query is { 2, 1, 7 };

#include "headers.h"

void dfs(vector<int>& query, unordered_map<int, vector<int>>& m, int start, int& ans, vector<int>& path) {
    if (start == query.size()) {
        ans = min(ans, path.back() - path.at(0) + 1);
        return;
    }

    int q = query[start];
    for (int idx : m[q]) {
        if (path.empty() || path.back() < idx) {
            path.push_back(idx);
            dfs(query, m, start+1, ans, path);
            path.pop_back();
        }
    }
}

int solve(vector<int>& input, vector<int>& query) {
    unordered_map<int, vector<int>> m;
    for (int q : query) {
        for (int i = 0; i < input.size(); ++i) {
            if (q == input[i]) {
                m[q].push_back(i);
            }
        }
    }

    vector<int> path;
    int ans = INT_MAX;
    dfs(query, m, 0, ans, path);
    return ans;
}

int main(int argc, char** argv) {
// Example: input is { 2, 5, 2, 8, 0, 1, 4, 7 }, query is { 2, 1, 7 };
    vector<int> input{2, 9, 9, 9, 9, 5, 2, 8, 0, 1, 4, 7};
    vector<int> query{2, 1, 7};
    cout << solve(input, query) << endl;
}
