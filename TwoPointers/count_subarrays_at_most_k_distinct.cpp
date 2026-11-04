/*
Count nonempty subarrays containing at most k distinct values.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long countSubarrays(const vector<int>& a, int k) {
//     long long count = 0;
//     for (int left = 0; left < static_cast<int>(a.size()); left++) {
//         unordered_set<int> seen;
//         for (int right = left; right < static_cast<int>(a.size()); right++) {
//             seen.insert(a[right]);
//             if (static_cast<int>(seen.size()) <= k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
//
// int main() {
//     cout << countSubarrays({1, 2, 1, 3}, 2) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(const vector<int>& a, int k) {
    if (k <= 0) {
        return 0;
    }

    unordered_map<int, int> freq;
    int left = 0;
    long long count = 0;
    for (int right = 0; right < static_cast<int>(a.size()); right++) {
        freq[a[right]]++;
        while (static_cast<int>(freq.size()) > k) {
            int value = a[left];
            freq[value]--;
            if (freq[value] == 0) {
                freq.erase(value);
            }
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int main() {
    cout << countSubarrays({1, 2, 1, 3}, 2) << '\n';
    return 0;
}
