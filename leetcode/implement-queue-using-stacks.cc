// Question: https://leetcode.com/problems/implement-queue-using-stacks/

#include "headers.h"

class Queue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    Queue() {
    }

    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            return s2.top();
        }
        return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s1.empty() && s2.empty());
    }
};

int main(int argc, char** argv) {
    Queue q;

    return 0;
}
