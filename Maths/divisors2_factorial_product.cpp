/*
CodeChef DIVISORS2. Read N M and N positive integers. For each A[i],
print the number of divisors of (A[i] * M!), modulo 1000000007.
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

const long long MOD = 1000000007;

long long modPower(long long base, long long exponent) {
    long long answer = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            answer = answer * base % MOD;
        }
        base = base * base % MOD;
        exponent /= 2;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }
    vector<int> values(n);
    int limit = m;
    for (int& value : values) {
        cin >> value;
        limit = max(limit, value);
    }

    vector<int> spf = smallestPrimeFactors(limit);
    vector<int> factorialExponent(limit + 1, 0);
    for (int i = 2; i <= m; i++) {
        int value = i;
        while (value > 1) {
            int p = spf[value];
            factorialExponent[p]++;
            value /= p;
        }
    }

    long long base = 1;
    vector<long long> inverseFactor(m + 1, 1);
    for (int p = 2; p <= m; p++) {
        if (factorialExponent[p] > 0) {
            int factor = factorialExponent[p] + 1;
            base = base * factor % MOD;
            inverseFactor[p] = modPower(factor, MOD - 2);
        }
    }

    for (int i = 0; i < n; i++) {
        int value = values[i];
        long long answer = base;
        while (value > 1) {
            int p = spf[value];
            int exponent = 0;
            do {
                value /= p;
                exponent++;
            } while (value > 1 && spf[value] == p);

            if (p <= m) {
                answer = answer * inverseFactor[p] % MOD;
            }
            answer = answer * (factorialExponent[p] + exponent + 1) % MOD;
        }
        if (i > 0) {
            cout << ' ';
        }
        cout << answer;
    }
    cout << '\n';
    return 0;
}
