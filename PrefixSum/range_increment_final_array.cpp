/*
Start with 100000 zeros at indices 1 through 100000.
Add 1 to every index in each inclusive range [l, r].
Input: Q, followed by Q pairs l r.
Output: all 100000 final values in index order.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     const int n = 100000;
//     int q;
//     if (!(cin >> q)) {
//         return 0;
//     }
//
//     vector<long long> a(n + 2, 0);
//     while (q--) {
//         int left, right;
//         cin >> left >> right;
//         for (int i = left; i <= right; i++) {
//             a[i]++;
//         }
//     }
//
//     for (int i = 1; i <= n; i++) {
//         if (i > 1) {
//             cout << ' ';
//         }
//         cout << a[i];
//     }
//     cout << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 100000;
    int q;
    if (!(cin >> q)) {
        return 0;
    }

    vector<long long> a(n + 2, 0);
    while (q--) {
        int left, right;
        cin >> left >> right;
        a[left]++;
        a[right + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        if (i > 1) {
            cout << ' ';
        }
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
