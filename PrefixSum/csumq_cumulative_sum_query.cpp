/*
Given an array of size N and Q queries,
each query contains two indices i and j.

Find the sum of all elements from index
i to j (inclusive) using 0-based indexing.

If i > j, swap the indices.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        prefix[i + 1] = prefix[i] + x;
    }

    int q;
    cin >> q;

    while (q--) {
        int i, j;
        cin >> i >> j;

        if (i > j) {
            swap(i, j);
        }

        long long sum = prefix[j + 1] - prefix[i];

        cout << sum << endl;
    }

    return 0;
}
