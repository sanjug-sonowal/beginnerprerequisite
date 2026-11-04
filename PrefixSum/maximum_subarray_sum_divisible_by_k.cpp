/*
Given an array of size N, find the maximum
subarray sum such that the size of the
subarray is divisible by K.
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
    vector<long long> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    long long ans = LLONG_MIN;

    for (int i = k; i <= n; i++) {
        long long sum = prefix[i] - prefix[i - k];

        dp[i] = sum;

        if (i >= 2 * k) {
            dp[i] = max(dp[i], sum + dp[i - k]);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
