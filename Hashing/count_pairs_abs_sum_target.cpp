/*
Given an array nums of size N, find the total number of pairs (i,j) [i<j] such that abs(nums[i] + nums[j]) = target, target >= 0.
Example: nums = [10, 5, 1, 3, 1], K = 2 -> Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {10, 5, 1, 3, 1};
    long long target = 2;
    unordered_map<long long, long long> freq;
    long long count = 0;
    for (long long x : nums) {
        if (target == 0) {
            long long need = -x;
            if (freq.find(need) != freq.end()) {
                count += freq[need];
            }
        } else {
            long long need1 = target - x;
            long long need2 = -target - x;
            if (freq.find(need1) != freq.end()) count += freq[need1];
            if (freq.find(need2) != freq.end()) count += freq[need2];
        }
        freq[x]++;
    }
    cout << count << endl;
    return 0;
}