// Question: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum % 2 == 0) {
            return (find_kth(nums1, nums2, sum/2) + find_kth(nums1, nums2, sum/2+1)) * 1.0 / 2;
        } else {
            return find_kth(nums1, nums2, sum/2+1);
        }
    }

private:
    int find_kth(vector<int> nums1, vector<int> nums2, int k) {
        if (nums1.size() > nums2.size()) {
            return find_kth(nums2, nums1, k);
        }
        if (nums1.size() == 0) {
            return nums2.at(k-1);
        }
        if (k == 1) {
            return nums1.at(0) < nums2.at(0) ? nums1.at(0) : nums2.at(0);
        }

        int p1 = k/2 < nums1.size() ? k/2 : nums1.size();
        int p2 = k-p1;
        if (nums1.at(p1-1) > nums2.at(p2-1)) {
            return find_kth(nums1, vector<int>(nums2.begin()+p2, nums2.end()), k-p2);
        } else if (nums1.at(p1-1) < nums2.at(p2-1)) {
            return find_kth(vector<int>(nums1.begin()+p1, nums1.end()), nums2, k-p1);
        } else {
            return nums1.at(p1-1);
        }
    }
};

int main(int argc, char** argv) {
    int n1[] = {3,5,7};
    int n2[] = {2};
    vector<int> nums1(n1, n1 + sizeof(n1) / sizeof(int));
    vector<int> nums2(n2, n2 + sizeof(n2) / sizeof(int));
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
