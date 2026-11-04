/*
Given an array of size N, find the largest and shortest subarray [i…j] with sum equal to K. In case the answer is not possible print (-1 -1). The array is not sorted.
Example: A = [2,2,1,4], Sum = 5 -> Output: 3,2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 2, 1, 4};
    int K = 5;
    int n = a.size();
    unordered_map<long long, int> firstOccur, lastOccur;
    firstOccur[0] = -1;
    lastOccur[0] = -1;
    long long prefix = 0;
    int maxLen = -1, minLen = INT_MAX;
    for (int j = 0; j < n; j++) {
        prefix += a[j];
        long long need = prefix - K;
        if (firstOccur.find(need) != firstOccur.end()) {
            maxLen = max(maxLen, j - firstOccur[need]);
            minLen = min(minLen, j - lastOccur[need]);
        }
        if (firstOccur.find(prefix) == firstOccur.end()) {
            firstOccur[prefix] = j;
        }
        lastOccur[prefix] = j;
    }
    if (maxLen == -1) {
        cout << -1 << " " << -1 << endl;
    } else {
        cout << maxLen << " " << minLen << endl;
    }
    return 0;
}