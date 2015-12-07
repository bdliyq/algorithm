// Question: https://leetcode.com/problems/min-stack/

#include "headers.h"

class MinStack {
public:
    void push(int x) {
        data_.push(x);
        if (min_.empty() || x < min_.top()) {
            min_.push(x);
        } else {
            min_.push(min_.top());
        }
    }

    void pop() {
        data_.pop();
        min_.pop();
    }

    int top() {
        return data_.top();
    }

    int getMin() {
        return min_.top();
    }
private:
    stack<int> data_;
    stack<int> min_;
};
