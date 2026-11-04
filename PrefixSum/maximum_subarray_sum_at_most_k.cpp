/*
Given an array of size N, find the maximum
subarray sum such that the size of the
subarray is at most K.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {0, -5, 6, 6, -3, 2, 2};
    int k = 3;
    int n = a.size() - 1;

    if (k <= 0 || n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    deque<int> dq;
    dq.push_back(0);

    long long ans = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }

        long long sum = prefix[i] - prefix[dq.front()];

        ans = max(ans, sum);

        while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << ans << endl;

    return 0;
}
