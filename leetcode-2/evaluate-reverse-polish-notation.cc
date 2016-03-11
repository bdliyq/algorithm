// Question: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto token : tokens) {
            if (token == "+") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x + y);
            } else if (token == "-") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x - y);
            } else if (token == "*") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x * y);
            } else if (token == "/") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x / y);
            } else {
                s.push(atoi(token.c_str()));
            }
        }
        return s.top();
    }
};
