/*
Given N inclusive integer ranges, answer Q inclusive queries.
For each query, count its integer points covered by at least K ranges.
All endpoints are in [0, 1000000].
Input: N Q K, followed by N ranges and then Q queries.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     const int limit = 1000000;
//     int n, q, k;
//     if (!(cin >> n >> q >> k)) {
//         return 0;
//     }
//
//     vector<int> coverage(limit + 2, 0);
//     for (int i = 0; i < n; i++) {
//         int left, right;
//         cin >> left >> right;
//         for (int point = left; point <= right; point++) {
//             coverage[point]++;
//         }
//     }
//
//     while (q--) {
//         int start, end;
//         cin >> start >> end;
//         int count = 0;
//         for (int point = start; point <= end; point++) {
//             if (coverage[point] >= k) {
//                 count++;
//             }
//         }
//         cout << count << '\n';
//     }
//
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    const int limit = 1000000;
    int n, q, k;
    if (!(cin >> n >> q >> k)) {
        return 0;
    }

    vector<int> coverage(limit + 2, 0);
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        coverage[left]++;
        coverage[right + 1]--;
    }

    vector<int> prefix(limit + 2, 0);
    int active = 0;
    for (int point = 0; point <= limit; point++) {
        active += coverage[point];
        prefix[point + 1] = prefix[point] + (active >= k);
    }

    while (q--) {
        int start, end;
        cin >> start >> end;
        cout << prefix[end + 1] - prefix[start] << '\n';
    }

    return 0;
}
