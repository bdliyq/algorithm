// Question: https://leetcode.com/problems/count-primes/

#include "headers.h"

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }

        // Sieve of Eratosthenes
        vector<bool> is_prime(n, true);
        for (int i = 2; i*i <= n; ++i) {
            if (!is_prime[i]) {
                continue;
            }
            for (int j = i*i; j < n; j += i) {
                is_prime[j] = false;
            }
        }

        return count(is_prime.begin()+2, is_prime.end(), true);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.countPrimes(19) << endl;
    return 0;
}
