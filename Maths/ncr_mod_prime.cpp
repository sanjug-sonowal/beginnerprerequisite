/*
Read Q pairs n r with 0 <= n <= 100000 and print C(n,r) modulo 1000000007.
Print zero when r is outside [0,n].
Applications: increasing arrays use C(M,N), stars and bars uses
C(N+K-1,K-1), and order-preserving interleavings use C(N+M,M).
*/

#include <bits/stdc++.h>
using namespace std;

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

    const int limit = 100000;
    int q;
    if (!(cin >> q)) {
        return 0;
    }

    vector<long long> factorial(limit + 1, 1), inverseFactorial(limit + 1, 1);
    for (int i = 1; i <= limit; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    inverseFactorial[limit] = modPower(factorial[limit], MOD - 2);
    for (int i = limit; i > 0; i--) {
        inverseFactorial[i - 1] = inverseFactorial[i] * i % MOD;
    }

    while (q--) {
        int n, r;
        cin >> n >> r;
        long long answer = 0;
        if (0 <= r && r <= n) {
            answer = factorial[n] * inverseFactorial[r] % MOD * inverseFactorial[n - r] % MOD;
        }
        cout << answer << '\n';
    }
    return 0;
}
