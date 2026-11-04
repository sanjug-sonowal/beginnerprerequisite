/*
Select exactly k elements to maximize their total happiness.
Values may be negative and 0 <= k <= N.
Input: N K, followed by N values.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long maxHappiness(vector<int> values, int k) {
//     vector<int> chosen(values.size(), 0);
//     fill(chosen.begin(), chosen.begin() + k, 1);
//     long long best = LLONG_MIN;
//     do {
//         long long sum = 0;
//         for (size_t i = 0; i < values.size(); i++) {
//             if (chosen[i]) {
//                 sum += values[i];
//             }
//         }
//         best = max(best, sum);
//     } while (prev_permutation(chosen.begin(), chosen.end()));
//     return best;
// }
//
// int main() {
//     int n, k;
//     if (!(cin >> n >> k)) {
//         return 0;
//     }
//     vector<int> values(n);
//     for (int& value : values) {
//         cin >> value;
//     }
//     cout << maxHappiness(move(values), k) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long maxHappiness(vector<int> values, int k) {
    sort(values.begin(), values.end(), greater<int>());
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += values[i];
    }
    return sum;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }
    vector<int> values(n);
    for (int& value : values) {
        cin >> value;
    }
    cout << maxHappiness(move(values), k) << '\n';
    return 0;
}
