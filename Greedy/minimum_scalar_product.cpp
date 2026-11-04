/*
Reorder two equal-length integer arrays to minimize their scalar product.
Values may be negative. The result fits in a signed 64-bit integer.
Google Code Jam format: T cases, each with N and two arrays.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long minScalarProduct(vector<int> a, vector<int> b) {
//     sort(b.begin(), b.end());
//     __int128 best = numeric_limits<__int128>::max();
//     do {
//         __int128 sum = 0;
//         for (size_t i = 0; i < a.size(); i++) {
//             sum += 1LL * a[i] * b[i];
//         }
//         best = min(best, sum);
//     } while (next_permutation(b.begin(), b.end()));
//     return static_cast<long long>(best);
// }
//
// int main() {
//     int tests;
//     if (!(cin >> tests)) {
//         return 0;
//     }
//     for (int test = 1; test <= tests; test++) {
//         int n;
//         cin >> n;
//         vector<int> a(n), b(n);
//         for (int& value : a) {
//             cin >> value;
//         }
//         for (int& value : b) {
//             cin >> value;
//         }
//         cout << "Case #" << test << ": " << minScalarProduct(move(a), move(b)) << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long minScalarProduct(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    __int128 sum = 0;
    for (size_t i = 0; i < a.size(); i++) {
        sum += 1LL * a[i] * b[i];
    }
    return static_cast<long long>(sum);
}

int main() {
    int tests;
    if (!(cin >> tests)) {
        return 0;
    }
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& value : a) {
            cin >> value;
        }
        for (int& value : b) {
            cin >> value;
        }
        cout << "Case #" << test << ": " << minScalarProduct(move(a), move(b)) << '\n';
    }
    return 0;
}
