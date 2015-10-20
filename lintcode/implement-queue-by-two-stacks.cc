// Question: http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/
#include <stack>
#include <iostream>
using namespace std;
class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        this->stack1.push(element);
    }

    int pop() {
        // write your code here
        if (!this->stack2.empty()) {
            int res = this->stack2.top();
            this->stack2.pop();
            return res;
        } else {
            while (!this->stack1.empty()) {
                this->stack2.push(this->stack1.top());
                this->stack1.pop();
            }
            if (!this->stack2.empty()) {
                int res = this->stack2.top();
                this->stack2.pop();
                return res;
            }
        }
        return 0;
    }

    int top() {
        // write your code here
        if (!this->stack2.empty()) {
            return this->stack2.top();
        } else {
            while (!this->stack1.empty()) {
                this->stack2.push(this->stack1.top());
                this->stack1.pop();
            }
            if (!this->stack2.empty()) {
                return this->stack2.top();
            }
        }
        return 0;
    }
};

int main(int argc, char** argv) {
    Queue q;
    q.push(1);
    std::cout << q.top() << std::endl;
    q.pop();
    q.push(2);
    q.push(3);
    std::cout << q.top() << std::endl;
    std::cout << q.pop() << std::endl;

    return 0;
}
