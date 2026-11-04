/*
Return the kth smallest element of a rotated ascending array of distinct
integers, where k is 1-based and 1 <= k <= N.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int kthSmallest(const vector<int>& nums, int k) {
//     vector<int> sorted = nums;
//     sort(sorted.begin(), sorted.end());
//     return sorted[k - 1];
// }
//
// int main() {
//     cout << kthSmallest({4, 5, 1, 2, 3}, 4) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(const vector<int>& nums, int k) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[(left + static_cast<long long>(k) - 1) % nums.size()];
}

int main() {
    cout << kthSmallest({4, 5, 1, 2, 3}, 4) << '\n';
    return 0;
}
