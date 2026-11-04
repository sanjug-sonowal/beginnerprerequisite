/*
Given an array nums of size N, find the total number of pairs (i,j) [i<j] such that nums[i] + nums[j] = target.
The array is not necessarily sorted.
Example: nums = [2,2,3,3,5,5], target = 5 -> Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 2, 3, 3, 5, 5};
    long long target = 5;
    unordered_map<long long, long long> freq;
    long long count = 0;
    for (long long x : nums) {
        long long need = target - x;
        if (freq.find(need) != freq.end()) {
            count += freq[need];
        }
        freq[x]++;
    }
    cout << count << endl;
    return 0;
}