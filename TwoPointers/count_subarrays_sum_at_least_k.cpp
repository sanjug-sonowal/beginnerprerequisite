/*
Count nonempty subarrays with sum at least k.
All array elements are nonnegative.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long countSubarrays(const vector<int>& a, long long k) {
//     long long count = 0;
//     for (int left = 0; left < static_cast<int>(a.size()); left++) {
//         long long sum = 0;
//         for (int right = left; right < static_cast<int>(a.size()); right++) {
//             sum += a[right];
//             if (sum >= k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
//
// int main() {
//     cout << countSubarrays({2, 1, 1, 5, 8}, 4) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(const vector<int>& a, long long k) {
    long long n = a.size();
    if (k <= 0) {
        return n * (n + 1) / 2;
    }

    int left = 0;
    long long sum = 0;
    long long count = 0;
    for (int right = 0; right < static_cast<int>(a.size()); right++) {
        sum += a[right];
        while (sum >= k) {
            sum -= a[left];
            left++;
        }
        count += left;
    }
    return count;
}

int main() {
    cout << countSubarrays({2, 1, 1, 5, 8}, 4) << '\n';
    return 0;
}
