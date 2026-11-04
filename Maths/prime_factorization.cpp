/*
Read a positive integer n and print its prime factors with multiplicity.
For 1, print an empty line.
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
    for (long long p = 2; p <= n / p; p++) {
        while (n % p == 0) {
            cout << p << ' ';
            n /= p;
        }
    }
    if (n > 1) {
        cout << n;
    }
    cout << '\n';
    return 0;
}
