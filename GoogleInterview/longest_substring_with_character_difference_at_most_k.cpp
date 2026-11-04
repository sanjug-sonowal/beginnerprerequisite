/*
Return the length of the longest substring whose maximum and minimum
character codes differ by at most k. Return 0 if none qualifies.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int longestSubstring(const string& s, int k) {
//     int best = 0;
//     for (int left = 0; left < static_cast<int>(s.size()); left++) {
//         int low = static_cast<unsigned char>(s[left]);
//         int high = low;
//         for (int right = left; right < static_cast<int>(s.size()); right++) {
//             int value = static_cast<unsigned char>(s[right]);
//             low = min(low, value);
//             high = max(high, value);
//             if (1LL * high - low <= k) {
//                 best = max(best, right - left + 1);
//             }
//         }
//     }
//     return best;
// }
//
// int main() {
//     cout << longestSubstring("RRRRR", 0) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(const string& s, int k) {
    if (k < 0) {
        return 0;
    }

    vector<int> freq(256, 0);
    int low = 0;
    int high = 0;
    int left = 0;
    int best = 0;

    for (int right = 0; right < static_cast<int>(s.size()); right++) {
        int value = static_cast<unsigned char>(s[right]);
        if (left == right) {
            low = value;
            high = value;
        } else {
            low = min(low, value);
            high = max(high, value);
        }
        freq[value]++;

        while (high - low > k) {
            int removed = static_cast<unsigned char>(s[left]);
            freq[removed]--;
            left++;
            while (freq[low] == 0) {
                low++;
            }
            while (freq[high] == 0) {
                high--;
            }
        }
        best = max(best, right - left + 1);
    }
    return best;
}

int main() {
    cout << longestSubstring("RRRRR", 0) << '\n';
    return 0;
}
