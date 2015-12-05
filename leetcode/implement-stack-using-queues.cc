// Question: https://leetcode.com/problems/implement-stack-using-queues/

#include "headers.h"

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q1_.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1_.empty()) {
            while (q2_.size() > 1) {
                q1_.push(q2_.front());
                q2_.pop();
            }
            q2_.pop();
        } else {
            while (q1_.size() > 1) {
                q2_.push(q1_.front());
                q1_.pop();
            }
            q1_.pop();
        }
    }

    // Get the top element.
    int top() {
        if (q1_.empty()) {
            while (q2_.size() > 1) {
                q1_.push(q2_.front());
                q2_.pop();
            }
            int ans = q2_.front();
            q1_.push(q2_.front());
            q2_.pop();
            return ans;
        } else {
            while (q1_.size() > 1) {
                q2_.push(q1_.front());
                q1_.pop();
            }
            int ans = q1_.front();
            q2_.push(q1_.front());
            q1_.pop();
            return ans;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1_.empty() && q2_.empty();
    }

private:
    queue<int> q1_;
    queue<int> q2_;
};

int main(int argc, char** argv) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
