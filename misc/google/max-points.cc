// Question: 二维平面上的点集合，给出在同一条线上的最多点数。

int max_points(vector<Point> points) {
    int len = points.size();
    if (len <= 2) {
        return len;
    }

    int ans = 0;
    unordered_map<float, int> m;
    for (int i = 0; i < len; ++i) {
        int dup = 1;
        m.clear();

        for (int j = i+1; j < len; ++j) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                ++dup;
            } else {
                float slope = (points[i].x == points[j].x) ? INT_MAX : (float)(points[i].y - points[j].y) / (float)(points[i].x - points[j].x);
                m[slope]++;
            }
        }

        ans = max(ans, dup);
        for (auto item : m) {
            ans = max(ans, item.second + dup);
        }
    }

    return ans;
}
