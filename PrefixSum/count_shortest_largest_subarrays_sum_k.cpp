/*
Given an array of size N, find the count of the shortest and the count of the largest subarrays whose sum of elements equals K.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int K = 3;
    int n = a.size();

    unordered_map<long long, int> firstOccur, lastOccur;
    firstOccur[0] = 0;
    lastOccur[0] = 0;

    vector<long long> prefix(n + 1, 0);

    int maxLen = 0, minLen = INT_MAX;

    for (int j = 1; j <= n; j++) {
        prefix[j] = prefix[j - 1] + a[j - 1];

        long long need = prefix[j] - K;

        if (firstOccur.find(need) != firstOccur.end()) {
            int lenMax = j - firstOccur[need];
            int lenMin = j - lastOccur[need];

            maxLen = max(maxLen, lenMax);
            minLen = min(minLen, lenMin);
        }

        if (firstOccur.find(prefix[j]) == firstOccur.end()) {
            firstOccur[prefix[j]] = j;
        }

        lastOccur[prefix[j]] = j;
    }

    if (maxLen == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    long long maxCount = 0, minCount = 0;

    for (int j = 1; j <= n; j++) {
        if (j >= maxLen &&
            prefix[j] - prefix[j - maxLen] == K) {
            maxCount++;
        }

        if (j >= minLen &&
            prefix[j] - prefix[j - minLen] == K) {
            minCount++;
        }
    }

    cout << maxCount << " " << minCount << endl;

    return 0;
}
