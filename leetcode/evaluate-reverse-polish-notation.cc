// Question: https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include "headers.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (i == 0) {
                s.push(atoi(tokens[i].c_str()));
            } else {
                if (tokens[i] == "+") {
                    int x = s.top(); s.pop();
                    int y = s.top(); s.pop();
                    s.push(y+x);
                } else if (tokens[i] == "-") {
                    int x = s.top(); s.pop();
                    int y = s.top(); s.pop();
                    s.push(y-x);
                } else if (tokens[i] == "*") {
                    int x = s.top(); s.pop();
                    int y = s.top(); s.pop();
                    s.push(y*x);
                } else if (tokens[i] == "/") {
                    int x = s.top(); s.pop();
                    int y = s.top(); s.pop();
                    s.push(y/x);
                } else {
                    s.push(atoi(tokens[i].c_str()));
                }
            }
        }
        return s.empty() ? 0 : s.top();
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        vector<string> tokens{"2","1","+","3","*"};
        cout << s.evalRPN(tokens) << endl;
    }
    {
        vector<string> tokens{"4","13","5","/","+"};
        cout << s.evalRPN(tokens) << endl;
    }
}
