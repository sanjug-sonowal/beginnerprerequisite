/*
Given an array nums of size N, find the total number of pairs (i,j) [i<j] such that abs(nums[i] - nums[j]) = target where target >= 0.
Example: nums = [7,2,2,3,3,5,5], target = 2 -> Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {7, 2, 2, 3, 3, 5, 5};
    long long target = 2;
    unordered_map<long long, long long> freq;
    long long count = 0;
    for (long long x : nums) {
        if (target == 0) {
            if (freq.find(x) != freq.end()) {
                count += freq[x];
            }
        } else {
            long long need1 = x + target;
            long long need2 = x - target;
            if (freq.find(need1) != freq.end()) count += freq[need1];
            if (freq.find(need2) != freq.end()) count += freq[need2];
        }
        freq[x]++;
    }
    cout << count << endl;
    return 0;
}