// Question: https://leetcode.com/problems/find-median-from-data-stream/

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (left.empty() && right.empty()) {
            left.push(num);
        } else if (left.empty()) {
            right.push(num);
        } else if (right.empty()) {
            left.push(num);
        } else {
            if (num > left.top()) {
                left.push(num);
            } else {
                right.push(num);
            }
        }

        while (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        while (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int count = left.size() + right.size();
        if (count % 2 == 0) {
            return (left.top() + right.top()) * 1.0 / 2;
        } else {
            return left.size() > right.size() ? left.top() : right.top();
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int, vector<int>, less<int>> right;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(int argc, char** argv) {
    MedianFinder mf;
    mf.addNum(1);
    // cout << mf.findMedian() << endl;
    mf.addNum(2);
    // cout << mf.findMedian() << endl;
    mf.addNum(3);
    // cout << mf.findMedian() << endl;
    mf.addNum(4);
    // cout << mf.findMedian() << endl;
    mf.addNum(5);
    // left:3,4,5
    // right:2,1
    cout << mf.findMedian() << endl;
}
