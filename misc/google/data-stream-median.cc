// Question: 无限数据流中，获取任意时间点的中位数。

class MedianFinder {
public:
    void add_num(int n) {
        if (left.empty() && right.empty()) {
            left.push(n);
        } else if (left.empty()) {
            right.push(n);
        } else if (right.empty()) {
            left.push(n);
        } else {
            if (n > left.top()) {
                left.push(n);
            } else {
                right.push(n);
            }
        }

        // adjust.
        while (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        while (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    float find_median() {
        int cnt = left.size() + right.size();
        if (cnt % 2 == 0) {
            return (left.top() + right.top()) * 1.0 / 2;
        } else {
            return left.size() > right.size() ? left.top() : right.top();
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int, vector<int>, less<int>> right;
};
