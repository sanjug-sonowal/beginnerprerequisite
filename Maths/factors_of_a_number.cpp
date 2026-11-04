/*
Read a positive integer n and print all its positive divisors in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<long long> large;
    for (long long d = 1; d <= n / d; d++) {
        if (n % d == 0) {
            cout << d << ' ';
            if (d != n / d) {
                large.push_back(n / d);
            }
        }
    }
    for (auto it = large.rbegin(); it != large.rend(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';
    return 0;
}
