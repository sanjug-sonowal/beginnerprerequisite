/*
Given an array of size N, find two non-empty,
non-overlapping subarrays such that their
combined sum is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, -5, 6, 6, -3, 2, 2};
    int n = a.size() - 1;

    if (n < 2) {
        cout << "Not possible" << endl;
        return 0;
    }

    vector<long long> p1(n + 2), pmax(n + 2);
    vector<long long> s1(n + 2), smax(n + 2);

    p1[1] = a[1];
    pmax[1] = a[1];

    for (int i = 2; i <= n; i++) {
        p1[i] = max((long long)a[i], p1[i - 1] + a[i]);
        pmax[i] = max(pmax[i - 1], p1[i]);
    }

    s1[n] = a[n];
    smax[n] = a[n];

    for (int i = n - 1; i >= 1; i--) {
        s1[i] = max((long long)a[i], a[i] + s1[i + 1]);
        smax[i] = max(smax[i + 1], s1[i]);
    }

    long long ans = LLONG_MIN;

    for (int i = 1; i < n; i++) {
        long long sum = pmax[i] + smax[i + 1];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
