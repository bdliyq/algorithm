// Question: 给定一个2d的grid，给定p个人，找出optimal meeting point，即所有人到达该point的距离和最小。

struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

struct cmpx {
    bool operator () (Point& p1, Point& p2) {
        return p1.x < p2.x;
    }
};

struct cmpy {
    bool operator () (Point& p1, Point& p2) {
        return p1.y < p2.y;
    }
};

// 实际上就是找x、y方向的中位数即可...
Point solve(vector<Point>& persons) {
    sort(persons.begin(), persons.end(), cmpx);
    int x = persons[persons.size()/2].x;

    sort(persons.begin(), persons.end(), cmpy);
    int y = persons[persons.size()/2].y;

    return Point(x, y);
}
