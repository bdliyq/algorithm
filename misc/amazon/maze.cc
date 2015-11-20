// Question: Maze

#include <queue>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int maze(vector<vector<int> > mat) {
    typedef pair<int, int> step;
    if (mat.size() == 0 || mat[0].size() == 0) {
        return 0;
    }

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};
    if (mat[0][0] == 9) {
        return 1;
    }

    queue<step> sq;
    sq.push(make_pair(0, 0));
    mat[0][0] = 1;
    while (!sq.empty()) {
        step curr = sq.front();
        sq.pop();

        for (int i = 0; i < 4; ++i) {
            step next = make_pair(curr.first + dx[i], curr.second + dy[i]);
            if (next.first >= 0 && next.first < mat.size() && next.second >= 0 && next.second < mat[0].size()) {
                if (mat[next.first][next.second] == 0) {
                    sq.push(next);
                    mat[next.first][next.second] = 1;
                } else if (mat[next.first][next.second] == 9) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    vector<vector<int> > m;
    vector<int> line;
    line.push_back(0);
    line.push_back(0);
    line.push_back(1);
    line.push_back(0);
    m.push_back(line);
    line.clear();

    line.push_back(0);
    line.push_back(1);
    line.push_back(0);
    line.push_back(0);
    m.push_back(line);
    line.clear();

    line.push_back(1);
    line.push_back(1);
    line.push_back(0);
    line.push_back(9);
    m.push_back(line);
    line.clear();

    std::cout << maze(m) << std::endl;

}
