/*
Given an array of size N, find the largest subarray [i…j] whose bit-wise XOR is K.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int K = 6;
    int n = a.size();
    unordered_map<int, int> firstOccur;
    firstOccur[0] = -1;
    int prefixXor = 0;
    int maxLen = 0;
    for (int j = 0; j < n; j++) {
        prefixXor ^= a[j];
        int need = prefixXor ^ K;
        if (firstOccur.find(need) != firstOccur.end()) {
            int i = firstOccur[need] + 1;
            int len = j - i + 1;
            maxLen = max(maxLen, len);
        }
        if (firstOccur.find(prefixXor) == firstOccur.end()) {
            firstOccur[prefixXor] = j;
        }
    }
    cout << maxLen << endl;
    return 0;
}