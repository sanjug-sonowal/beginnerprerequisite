/*
Given a sorted array a and thresholds k1 and k2, count index quadruplets
i < j < k < l with a[i] + a[j] > k1 and a[k] + a[l] > k2.
The array can contain negative numbers and duplicates.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// __int128 countQuadruplets(const vector<int>& a, int k1, int k2) {
//     int n = static_cast<int>(a.size());
//     __int128 count = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 for (int l = k + 1; l < n; l++) {
//                     if (1LL * a[i] + a[j] > k1 && 1LL * a[k] + a[l] > k2) {
//                         count++;
//                     }
//                 }
//             }
//         }
//     }
//     return count;
// }

#include <bits/stdc++.h>
using namespace std;

__int128 countQuadruplets(const vector<int>& a, int k1, int k2) {
    int n = static_cast<int>(a.size());
    if (n < 4) {
        return 0;
    }

    vector<long long> suffix(n, 0);
    int firstPartner = 0;
    for (int k = n - 2; k >= 2; k--) {
        while (firstPartner < n && 1LL * a[k] + a[firstPartner] <= k2) {
            firstPartner++;
        }
        suffix[k] = suffix[k + 1] + n - max(k + 1, firstPartner);
    }

    __int128 count = 0;
    int firstLeft = 0;
    for (int j = n - 3; j >= 1; j--) {
        while (firstLeft < j && 1LL * a[firstLeft] + a[j] <= k1) {
            firstLeft++;
        }

        if (firstLeft < j) {
            count += static_cast<__int128>(j - firstLeft) * suffix[j + 1];
        }
    }
    return count;
}

int main() {
    vector<int> a = {1, 1, 1, 1, 2, 2};
    __int128 count = countQuadruplets(a, 1, 3);

    string digits;
    do {
        digits.push_back('0' + static_cast<int>(count % 10));
        count /= 10;
    } while (count > 0);
    reverse(digits.begin(), digits.end());
    cout << digits << '\n';
    return 0;
}
