/*
Given an array of size N and an integer K,
find the count of subarrays such that the
sum of elements modulo K is equal to
the length of the subarray.

Condition:
sum modulo K == length of subarray, where K > 0.
Use the remainder in [0, K - 1], so the length must be less than K.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// typedef long long ll;
//
// int main() {
//     ll n, k;
//     cin >> n >> k;
//
//     vector<ll> a(n + 1);
//
//     for (ll i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//
//     ll count = 0;
//
//     for (ll i = 1; i <= n; i++) {
//         ll sum = 0;
//
//         for (ll j = i; j <= n; j++) {
//             sum += a[j];
//
//             ll len = j - i + 1;
//
//             ll remainder = sum % k;
//             if (remainder < 0) {
//                 remainder += k;
//             }
//
//             if (remainder == len) {
//                 count++;
//             }
//         }
//     }
//
//     cout << count << endl;
//
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    if (k == 1) {
        cout << 0 << '\n';
        return 0;
    }

    deque<long long> window = {0};
    unordered_map<long long, long long> freq;
    freq[0] = 1;
    long long adjusted = 0;
    long long count = 0;

    for (int j = 0; j < n; j++) {
        long long x;
        cin >> x;

        long long remainder = x % k;
        if (remainder < 0) {
            remainder += k;
        }

        long long step = remainder - 1;
        if (step < 0) {
            step += k;
        }

        if (adjusted >= k - step) {
            adjusted -= k - step;
        } else {
            adjusted += step;
        }

        if (static_cast<long long>(window.size()) == k) {
            long long expired = window.front();
            window.pop_front();
            freq[expired]--;
            if (freq[expired] == 0) {
                freq.erase(expired);
            }
        }

        auto match = freq.find(adjusted);
        if (match != freq.end()) {
            count += match->second;
        }

        window.push_back(adjusted);
        freq[adjusted]++;
    }

    cout << count << '\n';
    return 0;
}
