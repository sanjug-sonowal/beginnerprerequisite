/*
Read signed integers a, b and a positive modulus k. Print the normalized
remainders of a, b, a+b, a-b, and a*b, in that order.
*/

#include <bits/stdc++.h>
using namespace std;

long long normalize(long long value, long long k) {
    long long remainder = value % k;
    if (remainder < 0) {
        remainder += k;
    }
    return remainder;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, k;
    if (!(cin >> a >> b >> k)) {
        return 0;
    }
    long long x = normalize(a, k);
    long long y = normalize(b, k);
    cout << x << ' ' << y << ' '
         << static_cast<long long>((static_cast<__int128>(x) + y) % k) << ' '
         << normalize(x - y, k) << ' '
         << static_cast<long long>(static_cast<__int128>(x) * y % k) << '\n';
    return 0;
}
