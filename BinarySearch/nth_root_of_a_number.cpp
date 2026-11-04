/*
Given a positive exponent n and a nonnegative integer m, return the
integer x >= 0 with x^n = m, or -1 if no exact integer root exists.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int nthRoot(int n, int m) {
//     if (m <= 1 || n == 1) {
//         return m;
//     }
//     for (long long candidate = 2; candidate <= m; candidate++) {
//         long long power = 1;
//         for (int i = 0; i < n && power <= m; i++) {
//             power *= candidate;
//         }
//         if (power == m) {
//             return static_cast<int>(candidate);
//         }
//     }
//     return -1;
// }
//
// int main() {
//     cout << nthRoot(3, 27) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m) {
    if (m <= 1 || n == 1) {
        return m;
    }

    int left = 2;
    int right = m;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long power = 1;
        for (int i = 0; i < n && power <= m; i++) {
            power *= mid;
        }

        if (power == m) {
            return mid;
        }
        if (power < m) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout << nthRoot(3, 27) << '\n';
    return 0;
}
