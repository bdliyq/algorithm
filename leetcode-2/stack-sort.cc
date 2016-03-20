// Question: Stack sort.

class Solution {
public:
    void stack_sort(stack<int>& s) {
        stack<int> st;
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            while (!st.empty() && cur > st.top()) {
                s.push(st.top());
                st.pop();
            }
            st.push(cur);
        }

        while (!st.empty()) {
            s.push(st.top());
            st.pop();
        }
    }
};
