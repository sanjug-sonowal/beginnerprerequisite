/*
Given an array nums of size N, find the total number of pairs (i,j) [i<j] such that nums[i] - nums[j] = target.
Example: nums = [5,5,3,3,2,2], target = 2 -> Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {5, 5, 3, 3, 2, 2};
    long long target = 2;
    unordered_map<long long, long long> freq;
    long long count = 0;
    for (long long x : nums) {
        long long need = x + target;
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }
        freq[x]++;
    }
    cout << count << endl;
    return 0;
}