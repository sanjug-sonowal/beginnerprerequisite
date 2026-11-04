/*
Given an array nums of size N, find the total number of pairs (i,j) [i<j] such that (nums[i] + nums[j]) % 5 = 0 (nums[i] >= 0).
Example: nums = [2,2,5,5,3,3] -> Output: 5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2, 2, 5, 5, 3, 3};
    vector<int> freq(5, 0);
    long long count = 0;
    for (int x : nums) {
        int r = x % 5;
        int need = (5 - r) % 5;
        count += freq[need];
        freq[r]++;
    }
    cout << count << endl;
    return 0;
}