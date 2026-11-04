/*
Given an array nums of size N, find the total number of pairs (i,j) [i<j] such that (nums[i] + nums[j]) % k = 0 (nums[i] >= 0, k >= 2).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 2, 5, 5, 3, 3};
    int k = 5;
    unordered_map<int, int> freq;
    long long count = 0;
    for (int x : nums) {
        int r = x % k;
        int need = (k - r) % k;
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }
        freq[r]++;
    }
    cout << count << endl;
    return 0;
}