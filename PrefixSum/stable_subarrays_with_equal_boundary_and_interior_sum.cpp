/*
Count stable subarrays of the integer array capacity.
A stable subarray has at least three elements, and both
boundary elements equal the sum strictly between them.
Values may be negative or zero.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// class Solution {
// public:
//     long long countStableSubarrays(vector<int>& capacity) {
//         int n = capacity.size();
//         long long count = 0;
//
//         for (int left = 0; left + 2 < n; left++) {
//             long long interior = capacity[left + 1];
//             for (int right = left + 2; right < n; right++) {
//                 if (capacity[left] == capacity[right] && interior == capacity[right]) {
//                     count++;
//                 }
//                 interior += capacity[right];
//             }
//         }
//
//         return count;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + capacity[i];
        }

        map<pair<long long, int>, long long> freq;
        long long count = 0;

        for (int right = 2; right < n; right++) {
            int left = right - 2;
            freq[{prefix[left + 1], capacity[left]}]++;

            long long need = prefix[right] - capacity[right];
            auto match = freq.find({need, capacity[right]});
            if (match != freq.end()) {
                count += match->second;
            }
        }

        return count;
    }
};
