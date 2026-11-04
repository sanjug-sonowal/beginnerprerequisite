/*
Given an array of size N, count the number of subarrays [i…j] whose sum is K. The array is not sorted.
Example: [2,2,3,5,2,2,3,2,2,1], K = 8 -> Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 2, 3, 5, 2, 2, 3, 2, 2, 1};
    int K = 8;
    unordered_map<long long, long long> freq;
    freq[0] = 1;
    long long prefix = 0;
    long long count = 0;
    for (int x : a) {
        prefix += x;
        long long need = prefix - K;
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }
        freq[prefix]++;
    }
    cout << count << endl;
    return 0;
}