// Question: http://www.lintcode.com/en/problem/singleton/

#include <iostream>

class Solution {
protected:
    static Solution* instance_;

public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        if (!instance_) {
            instance_ = new Solution;
        }
        return instance_;
    }
};

Solution* Solution::instance_ = NULL;

int main(int argc, char** argv) {
    Solution* s1 = Solution::getInstance();
    Solution* s2 = Solution::getInstance();
    if (s1 == s2) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
}
