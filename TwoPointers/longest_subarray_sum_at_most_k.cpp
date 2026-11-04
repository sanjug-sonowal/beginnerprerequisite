/*
Return the length of the longest nonempty subarray with sum at most k.
All elements are nonnegative. Return 0 if no subarray qualifies.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int longestSubarray(const vector<int>& a, long long k) {
//     int best = 0;
//     for (int left = 0; left < static_cast<int>(a.size()); left++) {
//         long long sum = 0;
//         for (int right = left; right < static_cast<int>(a.size()); right++) {
//             sum += a[right];
//             if (sum <= k) {
//                 best = max(best, right - left + 1);
//             }
//         }
//     }
//     return best;
// }
//
// int main() {
//     cout << longestSubarray({2, 1, 1, 5, 8}, 4) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(const vector<int>& a, long long k) {
    if (k < 0) {
        return 0;
    }

    int left = 0;
    int best = 0;
    long long sum = 0;
    for (int right = 0; right < static_cast<int>(a.size()); right++) {
        sum += a[right];
        while (sum > k) {
            sum -= a[left];
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << longestSubarray({2, 1, 1, 5, 8}, 4) << '\n';
    return 0;
}
