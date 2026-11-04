/*
Given an array a of size N, find the count of triplets (i,j,k) with i < j < k such that (a[i] + a[j] + a[k]) % d == 0, where d > 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int d = 3;
    unordered_map<int, long long> freq;
    unordered_map<int, long long> pairFreq;
    long long count = 0;
    for (int x : a) {
        int r = x % d;
        if (r < 0) {
            r += d;
        }
        int need = (d - r) % d;
        if (pairFreq.find(need) != pairFreq.end()) {
            count += pairFreq[need];
        }
        for (auto &p : freq) {
            int otherR = p.first;
            long long otherCount = p.second;
            int newSum = ((long long)r + otherR) % d;
            pairFreq[newSum] += otherCount;
        }
        freq[r]++;
    }
    cout << count << endl;
    return 0;
}