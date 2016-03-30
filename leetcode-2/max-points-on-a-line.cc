// Question: https://leetcode.com/problems/max-points-on-a-line/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len <= 2) {
            return len;
        }

        int ans = 0;
        unordered_map<float, int> m;
        for (int i = 0; i < len; ++i) {
            m.clear();
            int dup = 1;
            for (int j = i+1; j < len; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++dup;
                } else {
                    float slope = (points[i].x == points[j].x) ? INT_MAX : (float)(points[i].y - points[j].y) / (float)(points[i].x - points[j].x);
                    m[slope]++;
                }
            }

            ans = max(ans, dup);
            for (auto s : m) {
                ans = max(ans, s.second + dup);
            }
        }

        return ans;
    }
};
