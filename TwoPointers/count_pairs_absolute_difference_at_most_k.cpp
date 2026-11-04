/*
Count index pairs i < j with |a[i] - a[j]| at most k.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long countPairs(vector<int> a, long long k) {
//     long long count = 0;
//     for (int i = 0; i < static_cast<int>(a.size()); i++) {
//         for (int j = i + 1; j < static_cast<int>(a.size()); j++) {
//             if (abs(1LL * a[i] - a[j]) <= k) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
//
// int main() {
//     cout << countPairs({1, 4, 2, 2}, 1) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long countPairs(vector<int> a, long long k) {
    if (k < 0) {
        return 0;
    }

    sort(a.begin(), a.end());
    int left = 0;
    long long count = 0;
    for (int right = 0; right < static_cast<int>(a.size()); right++) {
        while (1LL * a[right] - a[left] > k) {
            left++;
        }
        count += right - left;
    }
    return count;
}

int main() {
    cout << countPairs({1, 4, 2, 2}, 1) << '\n';
    return 0;
}
