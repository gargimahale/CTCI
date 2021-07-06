#include <bits/stdc++.h>
using namespace std;


// TC: O(m+n), SC: O(1) - As the overwite would never happen

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cap = m + n - 1, l1 = m - 1, l2 = n - 1;

        while (l2 >= 0) {
            if (l1 >= 0 && nums1[l1] >= nums2[l2]) {
                nums1[cap--] = nums1[l1--];
            }
            else {
                nums1[cap--] = nums2[l2--];
            }
        }
    }
};