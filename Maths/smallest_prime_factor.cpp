/*
Read Q integers in [1,1000000] and print their smallest prime factors.
Use 1 as the answer for 1.
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

    int q;
    if (!(cin >> q)) {
        return 0;
    }
    vector<int> spf = smallestPrimeFactors(1000000);
    spf[1] = 1;
    while (q--) {
        int value;
        cin >> value;
        cout << spf[value] << '\n';
    }
    return 0;
}
