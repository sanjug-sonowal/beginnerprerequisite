/*
Read N and N integers in [1,1000000]. Print the prime factors of each
integer with multiplicity on its own line. Use an empty line for 1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> smallestPrimeFactors(int limit) {
    vector<int> spf(limit + 1, 0);
    for (int p = 2; p <= limit; p++) {
        if (spf[p] != 0) {
            continue;
        }
        spf[p] = p;
        for (long long multiple = 1LL * p * p; multiple <= limit; multiple += p) {
            if (spf[multiple] == 0) {
                spf[multiple] = p;
            }
        }
    }
    return spf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> values(n);
    int limit = 1;
    for (int& value : values) {
        cin >> value;
        limit = max(limit, value);
    }
    vector<int> spf = smallestPrimeFactors(limit);
    for (int value : values) {
        while (value > 1) {
            int p = spf[value];
            cout << p;
            value /= p;
            if (value > 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
