/*
Return the number of right rotations modulo N in a nonempty rotated
ascending array of distinct integers.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int countRotations(const vector<int>& nums) {
//     return static_cast<int>(min_element(nums.begin(), nums.end()) - nums.begin());
// }
//
// int main() {
//     cout << countRotations({4, 5, 1, 2, 3}) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int countRotations(const vector<int>& nums) {
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
    return left;
}

int main() {
    cout << countRotations({4, 5, 1, 2, 3}) << '\n';
    return 0;
}
