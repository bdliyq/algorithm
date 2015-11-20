// Question: K nearest points.

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

double get_dist_square(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

Point g_origin;
struct cmp {
    bool operator() (const Point& p1, const Point& p2) {
        return get_dist_square(p1, g_origin) >= get_dist_square(p2, g_origin);
    }
};

vector<Point> k_nearest_points(vector<Point> points, Point origin, int k) {
    if (points.empty() || points.size() <= k) {
        return points;
    }

    g_origin = origin;

    priority_queue<Point, vector<Point>, cmp> pointq;
    for (size_t i = 0; i < points.size(); ++i) {
        pointq.push(points[i]);
        if (pointq.size() > k) {
            pointq.pop();
        }
    }

    vector<Point> ans;
    while (!pointq.empty()) {
        ans.push_back(pointq.top());
        pointq.pop();
    }

    return ans;
}

int main(int argc, char** argv) {
    vector<Point> points;
    points.push_back(Point(1,2));
    points.push_back(Point(10,20));
    points.push_back(Point(3,5));
    points.push_back(Point(4,4));
    points.push_back(Point(-1,2));
    points.push_back(Point(-21,2));
    points.push_back(Point(1,-2));

    Point origin(0, 0);
    int k = 4;

    vector<Point> nearest = k_nearest_points(points, origin, k);
    for (size_t i = 0; i < nearest.size(); ++i) {
        std::cout << nearest.at(i).x << " " << nearest.at(i).y << std::endl;
    }
}
