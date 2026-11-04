/*
Find the 0-based index of the first element strictly greater than x
in a nondecreasing array. Return the array size if none exists.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int upperBoundIndex(const vector<int>& nums, int x) {
//     int n = static_cast<int>(nums.size());
//     for (int i = 0; i < n; i++) {
//         if (nums[i] > x) {
//             return i;
//         }
//     }
//     return n;
// }
//
// int main() {
//     cout << upperBoundIndex({1, 2, 2, 4}, 2) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int upperBoundIndex(const vector<int>& nums, int x) {
    int left = 0;
    int right = static_cast<int>(nums.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    cout << upperBoundIndex({1, 2, 2, 4}, 2) << '\n';
    return 0;
}
