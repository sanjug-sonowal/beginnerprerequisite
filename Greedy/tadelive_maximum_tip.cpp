/*
Assign every order to Andy or Bob to maximize total tips.
Andy can handle up to X orders and Bob up to Y, with X + Y >= N.
Input: N X Y, then Andy's N tips and Bob's N tips.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long maxTip(const vector<int>& a, const vector<int>& b, int x, int y) {
//     int n = static_cast<int>(a.size());
//     long long best = LLONG_MIN;
//     for (int andy = max(0, n - y); andy <= min(x, n); andy++) {
//         vector<int> chosen(n, 0);
//         fill(chosen.begin(), chosen.begin() + andy, 1);
//         do {
//             long long total = 0;
//             for (int i = 0; i < n; i++) {
//                 total += chosen[i] ? a[i] : b[i];
//             }
//             best = max(best, total);
//         } while (prev_permutation(chosen.begin(), chosen.end()));
//     }
//     return best;
// }
//
// int main() {
//     int n, x, y;
//     if (!(cin >> n >> x >> y)) {
//         return 0;
//     }
//     vector<int> a(n), b(n);
//     for (int& tip : a) {
//         cin >> tip;
//     }
//     for (int& tip : b) {
//         cin >> tip;
//     }
//     cout << maxTip(a, b, x, y) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long maxTip(const vector<int>& a, const vector<int>& b, int x, int y) {
    int n = static_cast<int>(a.size());
    vector<long long> gains;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += b[i];
        gains.push_back(1LL * a[i] - b[i]);
    }

    sort(gains.begin(), gains.end(), greater<long long>());
    int required = max(0, n - y);
    int allowed = min(x, n);
    for (int i = 0; i < allowed; i++) {
        if (i >= required && gains[i] <= 0) {
            break;
        }
        total += gains[i];
    }
    return total;
}

int main() {
    int n, x, y;
    if (!(cin >> n >> x >> y)) {
        return 0;
    }
    vector<int> a(n), b(n);
    for (int& tip : a) {
        cin >> tip;
    }
    for (int& tip : b) {
        cin >> tip;
    }
    cout << maxTip(a, b, x, y) << '\n';
    return 0;
}
