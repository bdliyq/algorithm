// Question: https://leetcode.com/problems/min-stack/

class MinStack {
public:
    void push(int x) {
        data_.push(x);
        if (min_.empty()) {
            min_.push(x);
        } else {
            if (min_.top() < x) {
                min_.push(min_.top());
            } else {
                min_.push(x);
            }
        }
    }

    void pop() {
        if (!data_.empty()) {
            data_.pop();
            min_.pop();
        }
    }

    int top() {
        if (data_.empty()) {
            return 0;
        }
        return data_.top();
    }

    int getMin() {
        if (min_.empty()) {
            return 0;
        }
        return min_.top();
    }

private:
    stack<int> data_;
    stack<int> min_;
};
