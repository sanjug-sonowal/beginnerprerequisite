/*
Find the shortest subarray whose bit-wise XOR is K.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int K = 6;
    int n = a.size();
    unordered_map<int, int> lastOccur;
    lastOccur[0] = -1;
    int prefixXor = 0;
    int minLen = INT_MAX;
    for (int j = 0; j < n; j++) {
        prefixXor ^= a[j];
        int need = prefixXor ^ K;
        if (lastOccur.find(need) != lastOccur.end()) {
            int i = lastOccur[need] + 1;
            int len = j - i + 1;
            minLen = min(minLen, len);
        }
        lastOccur[prefixXor] = j;
    }
    if (minLen == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minLen << endl;
    }
    return 0;
}