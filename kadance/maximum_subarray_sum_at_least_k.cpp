/*
Given an array of size N, find the maximum
subarray sum such that the size of the
subarray is at least K.

If the maximum sum is negative, print 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, -5, 6, 6, -3, 2, 2};
    int k = 3;
    int n = a.size() - 1;

    if (k > n || k <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> prefix(n + 1, 0);
    vector<long long> pmax(n + 1, 0);

    pmax[1] = a[1];

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];

        if (i > 1) {
            pmax[i] = max((long long)a[i],
                          pmax[i - 1] + a[i]);
        }
    }

    long long ans = 0;

    for (int i = k; i <= n; i++) {
        long long sum = prefix[i] - prefix[i - k];

        if (i > k) {
            sum += max(0LL, pmax[i - k]);
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
