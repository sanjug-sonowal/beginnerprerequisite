/*
Read n and print all primes at most n in increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<bool> composite(n + 1, false);
    for (int p = 2; p <= n / p; p++) {
        if (!composite[p]) {
            for (long long multiple = 1LL * p * p; multiple <= n; multiple += p) {
                composite[multiple] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!composite[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
