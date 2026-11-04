/*
Given an array of size N, count the number of subarrays [i…j] whose bit-wise XOR is K.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int K = 6;
    unordered_map<int, int> freq;
    freq[0] = 1;
    int prefixXor = 0;
    long long count = 0;
    for (int x : a) {
        prefixXor ^= x;
        int need = prefixXor ^ K;
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }
        freq[prefixXor]++;
    }
    cout << count << endl;
    return 0;
}